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

pair<pair<int, int>, int> bfs(int sharksize, pair<int, int>& sharkidx, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    pair<int, int> sharkidx;
    vector<vector<int>> v(N, vector<int>(N, 0));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> v[row][col];
            if (v[row][col] == 9) {
                sharkidx = { row, col };
                v[row][col] = 0;
            }
        }
    }

    int sharksize = 2, sharkfeed = 0;
    int time = 0;
    while (1) {
        pair<pair<int, int>, int> cur = bfs(sharksize, sharkidx, v);
        int curTime = cur.second;
        if (curTime == 1000000) break;

        time += curTime;
        v[cur.first.first][cur.first.second] = 0;
        sharkidx = { cur.first.first, cur.first.second };
        sharkfeed++;
        
        if (sharkfeed == sharksize) {
            sharksize++;
            sharkfeed = 0;
        }
    }

    cout << time;

    return 0;
}

pair<pair<int, int>, int> bfs(int sharksize, pair<int, int>& sharkidx, vector<vector<int>>& v) {
    vector<vector<bool>> isVisited(v.size(), vector<bool>(v.size(), false));
    pair<pair<int, int>, int> mintime = { {-1, -1}, 1000000 };

    int dy[4] = { -1, 0, 0, 1 };
    int dx[4] = { 0, -1, 1, 0 };

    queue<pair<pair<int, int>, int>> q;
    q.push({ sharkidx, 0 });
    isVisited[sharkidx.first][sharkidx.second] = true;

    while (!q.empty()) {
        int crow = q.front().first.first;
        int ccol = q.front().first.second;
        int curTime = q.front().second;
        q.pop();
        
        if (curTime + 1 > mintime.second) continue;

        for (int i = 0; i < 4; i++) {
            int nrow = crow + dy[i];
            int ncol = ccol + dx[i];

            if (nrow >= v.size() || ncol >= v.size() || nrow < 0 || ncol < 0) continue;
            if (sharksize < v[nrow][ncol] || isVisited[nrow][ncol]) continue;

            isVisited[nrow][ncol] = true;

            if (sharksize >= v[nrow][ncol])  q.push({ {nrow, ncol}, curTime + 1 });
            
            if(sharksize > v[nrow][ncol] && v[nrow][ncol] != 0){
                if (curTime + 1 < mintime.second) mintime = { {nrow, ncol}, curTime + 1 };
                if (curTime + 1 == mintime.second) {
                    if (nrow < mintime.first.first) mintime = { {nrow, ncol}, curTime + 1 };
                    else if (nrow == mintime.first.first && ncol < mintime.first.second)
                        mintime = { {nrow, ncol}, curTime + 1 };
                }
            }
        }
    }
    return mintime;
}