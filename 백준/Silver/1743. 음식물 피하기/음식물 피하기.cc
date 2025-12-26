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

int bfs(int row, int col, vector<vector<char>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<vector<char>> v(N, vector<char>(M, '.'));

    for (int i = 0; i < K; i++) {
        int r, c; cin >> r >> c;
        r--; c--;
        v[r][c] = '#';
    }

    int ans = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (v[row][col] == '#') ans = max(ans, bfs(row, col, v));
        }
    }

    cout << ans;

    return 0;
}

int bfs(int row, int col, vector<vector<char>>& v) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ row, col });
    v[row][col] = '.';

    int size = 1;

    while (!q.empty()) {
        int colRow = q.front().first;
        int colCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = colRow + dy[i];
            int nextCol = colCol + dx[i];

            if (nextRow >= v.size() || nextCol >= v[0].size() || nextRow < 0 || nextCol < 0) continue;
            if (v[nextRow][nextCol] == '.') continue;

            v[nextRow][nextCol] = '.';
            size++;
            q.push({ nextRow, nextCol });
        }
    }

    return size;
}