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
//int memo[1001][3];
long long memo[10001];
long long preNode[1001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

void dijkstra(int start, vector<vector<pair<int, int>>>& edge);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> edge(N + 1);
    for (int i = 0; i < M; i++) {
        int start, end, cost;
        cin >> start >> end >> cost;
        edge[start].push_back({ end, cost });
    }

    fill(memo, memo + 1001, 1e9);
    fill(preNode, preNode + 1001, 0);

    int s, e; cin >> s >> e;
    dijkstra(s, edge);

    vector<int> path;
    int cur = e;
    while (1) {
        path.push_back(cur);
        if (cur == s) break;
        cur = preNode[cur];
    }
    reverse(path.begin(), path.end());

    cout << memo[e] << '\n'
        << path.size() << '\n';
    for (auto& p : path) cout << p << ' ';

    return 0;
}

void dijkstra(int start, vector<vector<pair<int, int>>>& edge) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    memo[start] = 0;

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > memo[curNode]) continue;

        for (int i = 0; i < edge[curNode].size(); i++) {
            int nextCost = curCost + edge[curNode][i].second;
            int nextNode = edge[curNode][i].first;

            if(nextCost < memo[nextNode]){
                memo[nextNode] = nextCost;
                preNode[nextNode] = curNode;
                pq.push({ nextCost, nextNode });
            }
        }
    }
    return;
}