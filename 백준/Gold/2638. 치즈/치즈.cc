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
//int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void outsideBFS(queue<pair<int, int>>& q, vector<vector<int>>& v, vector<vector<bool>>& isVisited);
bool check(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<vector<bool>> isVisited(N, vector<bool>(M, false));
    
    pair<int, int> start = { -1, -1 };
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) cin >> v[row][col];
    }

    queue<pair<int, int>> q;
    q.push({ 0,0 });
    isVisited[0][0] = true;
    outsideBFS(q, v, isVisited);

    int time = 0;
    while (1) {
        queue<pair<int, int>> cheese;
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (v[row][col] == 1 && check(row, col, v, isVisited))
                    cheese.push({ row, col });
            }
        }

        if (cheese.empty()) break;

        while (!cheese.empty()) {
            pair<int, int> c = cheese.front();

            v[c.first][c.second] = 0;
            isVisited[c.first][c.second] = true;
            q.push(c);
            cheese.pop();
        }
        outsideBFS(q, v, isVisited);

        time++;
    }

    cout << time;

    return 0;
}

void outsideBFS(queue<pair<int, int>>& q, vector<vector<int>>& v, vector<vector<bool>>& isVisited) {
    while (!q.empty()) {
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= v.size() || ncol >= v[0].size() || nrow < 0 || ncol < 0 || isVisited[nrow][ncol] || v[nrow][ncol] != 0) continue;

            isVisited[nrow][ncol] = true;
            q.push({ nrow, ncol });
        }
    }
    return;
}

bool check(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int nrow = row + dy[i];
        int ncol = col + dx[i];

        if (nrow >= v.size() || ncol >= v[0].size() || nrow < 0 || ncol < 0) continue;
        if ((v[nrow][ncol] == 0 && isVisited[nrow][ncol])) count++;
    }
    if (count >= 2) return true;
    return false;
}