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

bool isVisited[10][10][10][10];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void bfs(pair<int, int>& red, pair<int, int>& blue, vector<vector<char>>& v);
void move(int i, pair<int, int>& bfirst, pair<int, int>& blast, vector<vector<char>>& v);
bool check(int i, pair<int, int>& red, pair<int, int>& blue);

struct ball {
    pair<int, int> red;
    pair<int, int> blue;
    int level;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<char>> v(N, vector<char>(M));
    pair<int, int> red, blue;
    string tmp;
    for (int row = 0; row < N; row++) {
        cin >> tmp;
        for (int col = 0; col < M; col++) {
            v[row][col] = tmp[col];
            if (v[row][col] == 'R') {
                red = { row, col };
                v[row][col] = '.';
            }
            if (v[row][col] == 'B') {
                blue = { row, col };
                v[row][col] = '.';
            }
        }
    }

    bfs(red, blue, v);

    return 0;
}

void bfs(pair<int, int>& red, pair<int, int>& blue, vector<vector<char>>& v) {

    queue<ball> q;
    q.push({ red, blue, 0 });
    isVisited[red.first][red.second][blue.first][blue.second] = true;

    while (!q.empty()) {
        pair<int, int> curRed = q.front().red;
        pair<int, int> curBlue = q.front().blue;
        int curLevel = q.front().level;
        q.pop();

        if (curLevel >= 10) continue;

        for (int i = 0; i < 4; i++) {
            pair<int, int> nextRed = curRed;
            pair<int, int> nextBlue = curBlue;

            if (check(i, nextRed, nextBlue)) move(i, nextRed, nextBlue, v);
            else move(i, nextBlue, nextRed, v);

            if (v[nextBlue.first][nextBlue.second] == 'O') continue;
            if (v[nextRed.first][nextRed.second] == 'O') {
                cout << curLevel + 1;
                return;
            }

            if (isVisited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second]) continue;
            isVisited[nextRed.first][nextRed.second][nextBlue.first][nextBlue.second] = true;
            q.push({ nextRed, nextBlue, curLevel + 1 });
        }
    }
    cout << -1;
}

void move(int i, pair<int, int>& bfirst, pair<int, int>& blast, vector<vector<char>>& v) {
    while (true) {
        int nrow = bfirst.first + dy[i];
        int ncol = bfirst.second + dx[i];
        if (v[nrow][ncol] == '#') break;

        bfirst.first = nrow;
        bfirst.second = ncol;
        if (v[nrow][ncol] == 'O') break;
    }

    while (true) {
        int nrow = blast.first + dy[i];
        int ncol = blast.second + dx[i];
        if (v[nrow][ncol] == '#') break;

        if (v[bfirst.first][bfirst.second] != 'O' && nrow == bfirst.first && ncol == bfirst.second) break;

        blast.first = nrow;
        blast.second = ncol;
        if (v[nrow][ncol] == 'O') break;
    }
}

bool check(int i, pair<int, int>& red, pair<int, int>& blue) {
    if (i == 0) return red.first > blue.first;
    if (i == 1) return red.first < blue.first;
    if (i == 2) return red.second > blue.second;
    if (i == 3) return red.second < blue.second;
    return false;
}