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

bool bfs(pair<int, int> start, pair<int, int> end, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        int tc; cin >> tc;
        
        vector<vector<bool>> isVisited(100, vector<bool>(100, false));
        pair<int, int> start, end;
        for (int row = 0; row < 100; row++) {
            string tmp; cin >> tmp;
            for (int col = 0; col < 100; col++) {
                if (tmp[col] - '0' == 1) isVisited[row][col] = true;
                if (tmp[col] - '0' == 2) start = { row, col };
                if (tmp[col] - '0' == 3) end = { row, col };
            }
        }

        cout << "#" << t << " ";
        if (bfs(start, end, isVisited)) cout << 1;
        else cout << 0;
        cout << '\n';
    }
    return 0;
}

bool bfs(pair<int, int> start, pair<int, int> end, vector<vector<bool>>& isVisited) {
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ start.first, start.second });
    isVisited[start.first][start.second] = true;

    bool isAble = false;
    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextRow = curRow + dy[i];
            int nextCol = curCol + dx[i];

            if (nextRow >= isVisited.size() || nextCol >= isVisited[nextRow].size() || nextRow < 0 || nextCol < 0) continue;
            if (isVisited[nextRow][nextCol]) continue;

            if (nextRow == end.first && nextCol == end.second) {
                isAble = true;
                break;
            }

            isVisited[nextRow][nextCol] = true;
            q.push({ nextRow, nextCol });
        }
        if (isAble) break;
    }

    return isAble;
}