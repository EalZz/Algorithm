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

void bfs(int row, int col, vector<vector<int>>& map, vector<vector<bool>>& isVisited);

int dy[8] = { 1, 1, 1, 0, -1, -1, -1, 0 };
int dx[8] = { 1, 0, -1, -1, -1, 0, 1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;
        
        int N; cin >> N;
        vector<vector<char>> v(N, vector<char>(N));
        vector<vector<int>> map(N, vector<int>(N, 0));
        vector<vector<bool>> isVisited(N, vector<bool>(N, false));
        vector<pair<int, int>> mine, start;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                cin >> v[row][col];
                if (v[row][col] == '*') {
                    mine.push_back({ row, col });
                    isVisited[row][col] = true;
                    map[row][col] = -1;
                }
            }
        }

        for (auto& loca : mine) {
            int row = loca.first;
            int col = loca.second;

            for (int i = 0; i < 8; i++) {
                int nextRow = row + dy[i];
                int nextCol = col + dx[i];

                if (nextRow >= N || nextCol >= N || nextRow < 0 || nextCol < 0) continue;
                if (map[nextRow][nextCol] == -1) continue;
                
                map[nextRow][nextCol]++;
            }
        }

        int ans = 0;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (map[row][col] != 0 || isVisited[row][col]) continue;
                ans++;
                bfs(row, col, map, isVisited);
            }
        }

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (!isVisited[row][col]) ans++;
            }
        }

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}

void bfs(int row, int col, vector<vector<int>>& map, vector<vector<bool>>& isVisited) {
    queue<pair<int, int>> q;
    q.push({ row, col });
    isVisited[row][col] = true;

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= map.size() || nextCol >= map.size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol] || map[nextRow][nextCol] == -1) continue;

            isVisited[nextRow][nextCol] = true;
            if (map[nextRow][nextCol] == 0) q.push({ nextRow, nextCol });
        }
    }

    return;
}