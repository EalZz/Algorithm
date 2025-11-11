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

using namespace std;

void dijkstra(int row, int col, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;
        
        int N; cin >> N;
        vector<vector<int>> v(N, vector<int>(N)), dp(N, vector<int>(N, 0));
        for (int row = 0; row < N; row++) {
            string tmp; cin >> tmp;
            for (int col = 0; col < N; col++) v[row][col] = tmp[col] - '0';
        }

        cout << "#" << t << " ";
        dijkstra(0, 0, v);
        cout << '\n';
    }
    return 0;
}

void dijkstra(int row, int col, vector<vector<int>>& v) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    int N = v.size();
    vector<vector<int>> dp(N, vector<int>(N, 1e9));
    dp[row][col] = v[row][col];
    vector<vector<bool>> isVisited(N, vector<bool>(N, false));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {row, col} });

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int crow = pq.top().second.first;
        int ccol = pq.top().second.second;
        pq.pop();

        if (isVisited[crow][ccol]) continue;
        isVisited[crow][ccol] = true;

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];
            if (nrow >= N || ncol >= N || nrow < 0 || ncol < 0) continue;

            int nextCost = curCost + v[nrow][ncol];
            if (nextCost > dp[nrow][ncol]) continue;

            dp[nrow][ncol] = nextCost;
            pq.push({ nextCost, {nrow, ncol} });
        }
    }

    cout << dp[N - 1][N - 1];

    return;
}