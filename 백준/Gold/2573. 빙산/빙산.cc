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

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) cin >> v[row][col];
    }

    int cnt = 0, ans = 0;
    while (1) {
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        int tcnt = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (isVisited[row][col] || v[row][col] == 0) continue;
                tcnt++;
                bfs(row, col, v, isVisited);
            }
        }

        if (tcnt != 1) {
            cnt = tcnt;
            break;
        }

        vector<vector<int>> tmp = v;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (v[row][col] == 0) continue;

                int water = 0;
                for (int i = 0; i < 4; i++) {
                    if (tmp[row + dy[i]][col + dx[i]] == 0) water++;
                }
                v[row][col] -= water;
                if (v[row][col] < 0) v[row][col] = 0;
            }
        }

        ans++;
    }

    if (cnt == 0) cout << 0;
    else cout << ans;

    return 0;
}

void bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited) {
    queue<pair<int, int>> q;
    q.push({ row, col });
    isVisited[row][col] = true;

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= v.size() || nextCol >= v[row].size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol] || v[nextRow][nextCol] == 0) continue;

            isVisited[nextRow][nextCol] = true;
            q.push({ nextRow, nextCol });
        }
    }

    return;
}