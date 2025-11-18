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
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<bool>> isVisited(n, vector<bool>(m, true));
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            int tmp; cin >> tmp;
            if (tmp == 1) isVisited[row][col] = false;
        }
    }

    int cnt = 0, ans = 0;
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (isVisited[row][col]) continue;
            cnt++;
            ans = max(ans, bfs(row, col, isVisited));
        }
    }

    cout << cnt << '\n' << ans;

    return 0;
}

int bfs(int row, int col, vector<vector<bool>>& isVisited) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ row, col });
    isVisited[row][col] = true;

    int ext = 1;
    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= isVisited.size() || nextCol >= isVisited[row].size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol]) continue;

            isVisited[nextRow][nextCol] = true;
            q.push({ nextRow, nextCol });
            ext++;
        }
    }

    return ext;
}