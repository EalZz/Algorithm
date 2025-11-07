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

void bfs(int row, int col, vector<vector<bool>>& isIsland);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int w, h;
    while (cin >> w && cin >> h) {
        if (w == 0 && h == 0) break;

        vector<vector<bool>> isIsland(h, vector<bool>(w));
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                int tmp; cin >> tmp;
                if (tmp == 1) isIsland[row][col] = false;
                else isIsland[row][col] = true;
            }
        }

        int ans = 0;
        for (int row = 0; row < h; row++) {
            for (int col = 0; col < w; col++) {
                if (isIsland[row][col]) continue;
                bfs(row, col, isIsland);
                ans++;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

void bfs(int row, int col, vector<vector<bool>>& isIsland) {
    int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
    int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ row, col });

    while (!q.empty()) {
        int crow = q.front().first;
        int ccol = q.front().second;
        isIsland[crow][ccol] = true;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= isIsland.size() || ncol >= isIsland[nrow].size() || nrow < 0 || ncol < 0) continue;
            if (isIsland[nrow][ncol]) continue;

            q.push({ nrow, ncol });
            isIsland[nrow][ncol] = true;
        }
    }
    return;
}