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

void bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isSink);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int maxh = 0, minh = 1e9;
    vector<vector<int>> v(N, vector<int>(N));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> v[row][col];
            maxh = max(maxh, v[row][col]);
            //minh = min(minh, v[row][col]);
        }
    }

    int ans = 0;
    for (int i = 0; i <= maxh; i++) {
        vector<vector<bool>> isSink(N, vector<bool>(N));
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (v[row][col] <= i) isSink[row][col] = true;
            }
        }

        int tmp = 0;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (isSink[row][col]) continue;
                tmp++;
                bfs(row, col, v, isSink);
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans;

    return 0;
}

void bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isSink) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ row, col });

    while (!q.empty()) {
        int crow = q.front().first;
        int ccol = q.front().second;
        isSink[crow][ccol] = true;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= v.size() || ncol >= v.size() || nrow < 0 || ncol < 0) continue;
            if (isSink[nrow][ncol]) continue;

            isSink[nrow][ncol] = true;
            q.push({ nrow, ncol });
        }
    }
    return;
}