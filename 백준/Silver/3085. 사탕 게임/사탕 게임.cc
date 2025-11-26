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

int bfs(int row, int col, vector<vector<char>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<vector<char>> v(N, vector<char>(N));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) cin >> v[row][col];
    }

    int ans = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N - 1; col++) {
            vector<vector<bool>> isVisited(N, vector<bool>(N, false));

            swap(v[row][col], v[row][col + 1]);
            ans = max(ans, max(bfs(row, col, v, isVisited), bfs(row, col + 1, v, isVisited)));
            swap(v[row][col], v[row][col + 1]);
        }
    }

    for (int col = 0; col < N; col++) {
        for (int row = 0; row < N - 1; row++) {
            vector<vector<bool>> isVisited(N, vector<bool>(N, false));

            swap(v[row][col], v[row + 1][col]);
            ans = max(ans, max(bfs(row, col, v, isVisited), bfs(row + 1, col, v, isVisited)));
            swap(v[row][col], v[row + 1][col]);
        }
    }

    cout << ans;

    return 0;
}

int bfs(int row, int col, vector<vector<char>>& v, vector<vector<bool>>& isVisited) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };
    char standard = v[row][col];

    queue<pair<int, int>> q;

    q.push({ row, col });
    isVisited[row][col] = true;

    int cnt1 = 0;
    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        cnt1++;

        for (int i = 0; i < 2; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= v.size() || nextCol >= v.size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol] || v[nextRow][nextCol] != standard) continue;

            q.push({ nextRow, nextCol });
            isVisited[nextRow][nextCol] = true;
        }
    }

    q.push({ row, col });
    isVisited[row][col] = true;

    int cnt2 = 0;
    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();
        cnt2++;

        for (int i = 2; i < 4; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= v.size() || nextCol >= v.size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol] || v[nextRow][nextCol] != standard) continue;

            q.push({ nextRow, nextCol });
            isVisited[nextRow][nextCol] = true;
        }
    }

    return max(cnt1, cnt2);
}