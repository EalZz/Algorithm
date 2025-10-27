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

void dijkstra(vector<int> start, vector<tuple<int, int, int>>& edge);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int M; cin >> M;
    vector<tuple<int, int, int>> edge(M);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = { a - 1, b - 1, c };
    }

    dijkstra(A, edge);

    return 0;
}

void dijkstra(vector<int> start, vector<tuple<int, int, int>>& edge) {
    map<vector<int>, long long> m; 
    priority_queue<pair<long long, vector<int>>, vector<pair<long long, vector<int>>>, greater<pair<long long, vector<int>>>> pq;

    pq.push({ 0, start });
    m[start] = 0;

    while (!pq.empty()) {
        long long cost = pq.top().first;
        vector<int> cur = pq.top().second;
        pq.pop();

        if (m[cur] < cost) continue;

        if (is_sorted(cur.begin(), cur.end())) {
            cout << cost;
            return;
        }

        for (const auto& e : edge) {
            int i, j, c;
            tie(i, j, c) = e;

            vector<int> next = cur;
            swap(next[i], next[j]);
            long long nextCost = cost + c;

            if (!m.count(next) || m[next] > nextCost) {
                m[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }
    cout << -1;
    return;
}
