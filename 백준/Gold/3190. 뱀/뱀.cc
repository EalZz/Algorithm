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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<vector<bool>> snake(N, vector<bool>(N, false));
    queue<pair<int, int>> s;
    s.push({ 0, 0 });
    snake[0][0] = true;

    vector<vector<bool>> apple(N, vector<bool>(N, false));
    int K; cin >> K;
    while (K--) {
        int row, col; cin >> row >> col;
        apple[row - 1][col - 1] = true;
    }

    int L; cin >> L;
    vector<pair<int, char>> cmd(L);
    for (int i = 0; i < L; i++) cin >> cmd[i].first >> cmd[i].second;

    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };
    int time = 0, preTime = 0, dir = 0, crow = 0, ccol = 0;
    bool isAble = true;
    for (int i = 0; i < L; i++) {
        int Ltime = cmd[i].first - preTime;
        while (Ltime--) {
            time++;
            int nrow = crow + dy[dir];
            int ncol = ccol + dx[dir];

            if (nrow >= N || ncol >= N || nrow < 0 || ncol < 0 || snake[nrow][ncol]) {
                isAble = false;
                break;
            }

            s.push({ nrow, ncol });
            snake[nrow][ncol] = true;
            if (apple[nrow][ncol]) apple[nrow][ncol] = false;
            else {
                snake[s.front().first][s.front().second] = false;
                s.pop();
            }

            crow = nrow; 
            ccol = ncol;
        }
        preTime = cmd[i].first;

        if (!isAble) break;

        if (cmd[i].second == 'L') {
            if (dir == 0) dir = 3;
            else dir--;
        }
        else {
            if (dir == 3) dir = 0;
            else dir++;
        }
    }

    while (isAble) {
        time++;
        int nrow = crow + dy[dir];
        int ncol = ccol + dx[dir];

        if (nrow >= N || ncol >= N || nrow < 0 || ncol < 0 || snake[nrow][ncol]) break;

        s.push({ nrow, ncol });
        snake[nrow][ncol] = true;
        if (apple[nrow][ncol]) apple[nrow][ncol] = false;
        else {
            snake[s.front().first][s.front().second] = false;
            s.pop();
        }

        crow = nrow;
        ccol = ncol;
    }

    cout << time;

    return 0;
}