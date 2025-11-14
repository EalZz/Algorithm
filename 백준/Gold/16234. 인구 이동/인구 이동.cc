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

bool bfs(int row, int col, int L, int R, vector<vector<int>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L, R; cin >> N >> L >> R;
    vector<vector<int>> v(N, vector<int>(N));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) cin >> v[row][col];
    }

    int ans = 0;
    while (1) {
        bool isAble = false;
        vector<vector<bool>> isVisited(N, vector<bool>(N, false));
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (isVisited[row][col]) continue;
                if (bfs(row, col, L, R, v, isVisited)) isAble = true;
            }
        }
        if (!isAble) break;
        ans++;
    }

    cout << ans;

    return 0;
}

bool bfs(int row, int col, int L, int R, vector<vector<int>>& v, vector<vector<bool>>& isVisited) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int sum = 0, cnt = 0;

    queue<pair<int, int>> q;
    vector<pair<int, int>> rv;
    q.push({ row, col });
    isVisited[row][col] = true;

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        rv.push_back({ curRow, curCol });
        cnt++;
        sum += v[curRow][curCol];

        for (int i = 0; i < 4; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= v.size() || nextCol >= v.size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol]) continue;

            int gap = abs(v[curRow][curCol] - v[nextRow][nextCol]);
            if (gap > R || gap < L) continue;

            isVisited[nextRow][nextCol] = true;
            q.push({ nextRow, nextCol });
        }
    }

    if (cnt >= 2) {
        int avg = sum / cnt;
        for (auto& rc : rv) v[rc.first][rc.second] = avg;
        return true;
    }

    else return false;
}