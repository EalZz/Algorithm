#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <memory>

using namespace std;
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
long long memo[100001];
//int memo[101][4];

void dijkstra(int node, vector<vector<pair<int, int>>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1);
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<vector<pair<int, int>>> v(T + 1);
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }

    int via1, via2;
    cin >> via1 >> via2;

    long long dist1 = 0, dist2 = 0;

    fill(memo, memo + T + 1, 1e9);
    dijkstra(1, v);
    dist1 += memo[via1];

    fill(memo, memo + T + 1, 1e9);
    dijkstra(via1, v);
    dist1 += memo[via2];
    
    fill(memo, memo + T + 1, 1e9);
    dijkstra(via2, v);
    dist1 += memo[T];

    fill(memo, memo + T + 1, 1e9);
    dijkstra(1, v);
    dist2 += memo[via2];

    fill(memo, memo + T + 1, 1e9);
    dijkstra(via2, v);
    dist2 += memo[via1];

    fill(memo, memo + T + 1, 1e9);
    dijkstra(via1, v);
    dist2 += memo[T];

    long long dist = min(dist1, dist2);

    if (dist >= 1e9) cout << -1;
    else cout << dist;

    return 0;
}

void dijkstra(int node, vector<vector<pair<int, int>>>& v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    memo[node] = 0;
    pq.push({ 0, node });

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > memo[curNode]) continue;

        for (int i = 0; i < v[curNode].size(); i++) {
            int nextCost = curCost + v[curNode][i].second;
            int nextNode = v[curNode][i].first;

            if (nextCost < memo[nextNode]) {
                memo[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }
    return;
}