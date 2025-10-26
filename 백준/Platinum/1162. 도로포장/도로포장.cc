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
const long long INF = 1e15;
long long memo[10001][21];

void dijkstra(int start, int K, vector<vector<pair<int, int>>>& edge);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<vector<pair<int, int>>> edge(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        edge[s].push_back({ e, cost });
        edge[e].push_back({ s, cost });
    }

    for(int i = 0; i <= 10000; i++) fill(memo[i], memo[i] + 21, INF);

    dijkstra(1, K, edge);

    long long ans = INF;
    for (int i = 0; i <= K; i++) ans = min(ans, memo[N][i]);
    cout << ans;

    return 0;
}

void dijkstra(int start, int K, vector<vector<pair<int, int>>>& edge) {
    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
    pq.push({ 0, {1, 0} });
    memo[1][0] = 0;

    while (!pq.empty()) {
        long long curCost = pq.top().first;
        int curNode = pq.top().second.first;
        int curCount = pq.top().second.second;
        pq.pop();

        if (memo[curNode][curCount] < curCost) continue;

        for (int i = 0; i < edge[curNode].size(); i++) {
            int nextNode = edge[curNode][i].first;
            long long nextCost = curCost + edge[curNode][i].second;

            if (memo[nextNode][curCount] > nextCost) {
                memo[nextNode][curCount] = nextCost;
                pq.push({ nextCost, {nextNode, curCount} });
            }

            if (curCount + 1 <= K && memo[nextNode][curCount + 1] > curCost) {
                memo[nextNode][curCount + 1] = curCost;
                pq.push({ curCost, {nextNode, curCount + 1} });
            }
        }
    }
    return;
}