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
int cnt = 0, cnt1 = 0;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];
long long memo[100001];

void dijkstra(int start, vector <vector<pair<int, int>>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(T + 1, vector<int>(3, 0));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    fill(memo, memo + 100001, 1e9);

    int start; cin >> start;

    vector<vector<pair<int, int>>> v(T + 1);
    while (N--) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
    }
    
    dijkstra(start, v);

    for (int i = 1; i <= T; i++) {
        if (i == start) cout << 0 << '\n';
        else if (memo[i] == 1e9) cout << "INF" << '\n';
        else cout << memo[i] << '\n';
    }

    return 0;
}

void dijkstra(int start, vector <vector<pair<int, int>>>& v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    memo[start] = 0;
    pq.push({ 0, start });

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