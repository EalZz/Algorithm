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
int memo[1001];

bool bfs(int row, int col, vector<vector<char>>& v, vector<bool>& key);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int h, w; cin >> h >> w;
        vector<vector<char>> v(h + 2, vector<char>(w + 2, '.'));
        for (int row = 1; row <= h; row++) {
            for (int col = 1; col <= w; col++) cin >> v[row][col];
        }

        vector<bool> key(26);
        string tmpkey; cin >> tmpkey;
        if (tmpkey != "0") {
            for (auto& k : tmpkey) key[k - 'a'] = true;
        }

        cnt = 0;
        while (bfs(0, 0, v, key));

        cout << cnt << '\n';
    }

    return 0;
}

bool bfs(int row, int col, vector<vector<char>>& v, vector<bool>& key) {
    vector<vector<bool>> isVisited(v.size(), vector<bool>(v[0].size(), false));
    bool isNewkey = false;

    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    queue<pair<int, int>> q;
    q.push({ row, col });
    isVisited[row][col] = true;

    while (!q.empty()) {
        int crow = q.front().first;
        int ccol = q.front().second;
        q.pop();
            
        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= v.size() || ncol >= v[0].size() || nrow < 0 || ncol < 0) continue;
            if (isVisited[nrow][ncol] || v[nrow][ncol] == '*') continue;
            if (v[nrow][ncol] >= 'A' && v[nrow][ncol] <= 'Z' && !key[v[nrow][ncol] - 'A']) continue;

            if (v[nrow][ncol] >= 'a' && v[nrow][ncol] <= 'z') {
                key[v[nrow][ncol] - 'a'] = true;
                v[nrow][ncol] = '.';
                isNewkey = true;
            }
            if (v[nrow][ncol] == '$') {
                cnt++;
                v[nrow][ncol] = '.';
            }

            isVisited[nrow][ncol] = true;
            q.push({ nrow, ncol });
        }
    }
    return isNewkey;
}
