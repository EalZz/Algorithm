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
#include <list>

using namespace std;

int bfs(int row, int col, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M, N, K; cin >> M >> N >> K;

    vector<vector<bool>> isVisited(M, vector<bool>(N, false));
    while (K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int row = y1; row < y2; row++) {
            for (int col = x1; col < x2; col++) isVisited[row][col] = true;
        }
    }

    int cnt = 0;
    vector<int> ans;
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            if (isVisited[row][col]) continue;
            cnt++;
            ans.push_back(bfs(row, col, isVisited));
        }
    }
    
    cout << cnt << '\n';
    sort(ans.begin(), ans.end());
    for (auto& a : ans) cout << a << ' ';

    return 0;
}

int bfs(int row, int col, vector<vector<bool>>& isVisited) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ row, col });
    isVisited[row][col] = true;

    int dim = 0;
    while (!q.empty()) {
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();
        dim++;

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= isVisited.size() || ncol >= isVisited[0].size() || nrow < 0 || ncol < 0) continue;
            if (isVisited[nrow][ncol]) continue;

            isVisited[nrow][ncol] = true;
            q.push({ nrow, ncol });
        }
    }

    return dim;
}