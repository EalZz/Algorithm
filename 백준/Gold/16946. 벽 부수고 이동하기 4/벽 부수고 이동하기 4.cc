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
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

int bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited, vector<pair<int, int>>& vp);

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M)), result(N, vector<int>(M)), area(N, vector<int>(M));
    vector<pair<int, int>> start;
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    string tmp;
    for (int row = 0; row < N; row++) {
        cin >> tmp;
        for (int col = 0; col < M; col++) {
            v[row][col] = result[row][col] = tmp[col] - '0';
            area[row][col] = 0;
            if (v[row][col] == 1) {
                area[row][col] = -1;
                start.push_back({ row, col });
                isVisited[row][col] = true;
            }
        }
    }

    int areaNum = 1;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (isVisited[row][col]) continue;
            vector<pair<int, int>> vp;
            int sum = bfs(row, col, v, isVisited, vp);

            for (int i = 0; i < vp.size(); i++) {
                v[vp[i].first][vp[i].second] = sum;
                area[vp[i].first][vp[i].second] = areaNum;
            }
            areaNum++;
        }
    }


    for (int i = 0; i < start.size(); i++) {
        vector<bool> isUsed(areaNum + 1, false);

        int crow = start[i].first;
        int ccol = start[i].second;

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= v.size() || ncol >= v[0].size() || nrow < 0 || ncol < 0) continue;
            if (area[nrow][ncol] <= 0 || isUsed[area[nrow][ncol]]) continue;

            isUsed[area[nrow][ncol]] = true;
            result[crow][ccol] += v[nrow][ncol];
        }
        result[crow][ccol] %= 10;
    }

    for (int row = 0; row < N; row++) {
        string tmp;
        for (int col = 0; col < M; col++) tmp.push_back(result[row][col] + '0');
        cout << tmp << '\n';
    }

    return 0;
}

int bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited, vector<pair<int, int>>& vp) {
    queue<pair<int, int>> q;
    q.push({ row, col });
    vp.push_back({ row, col });
    isVisited[row][col] = true;

    int sum = 1;
    while (!q.empty()) {
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= v.size() || ncol >= v[0].size() || nrow < 0 || ncol < 0) continue;
            if (v[nrow][ncol] == 1 || isVisited[nrow][ncol]) continue;

            isVisited[nrow][ncol] = true;
            q.push({ nrow, ncol });
            vp.push_back({ nrow, ncol });
            sum++;
        }
    }
    return sum;
}