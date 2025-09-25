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
//long long memo[1001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    vector<vector<int>> v(T, vector<int>(N, 0));
    vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    pair<int, int> start;
    for (int row = 0; row < T; row++) {
        for (int col = 0; col < N; col++) {
            cin >> v[row][col];
            if (v[row][col] == 2) {
                start = make_pair(row, col);
                isVisited[row][col] = true;
            }
            if (v[row][col] == 0) isVisited[row][col] = true;
        }
    }

    int dy[4] = { 0, 0, 1, -1 };
    int dx[4] = { 1, -1, 0, 0 };

    queue<pair<pair<int, int>, int>> q;
    q.push({ {start.first, start.second}, 0 });
    v[start.first][start.second] = 0;

    while (!q.empty()) {
        pair<int, int> curLoca = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (curLoca.first + dy[i] >= 0 && curLoca.second + dx[i] >= 0 && curLoca.first + dy[i] < T && curLoca.second + dx[i] < N
                && !isVisited[curLoca.first + dy[i]][curLoca.second + dx[i]]) {
                isVisited[curLoca.first + dy[i]][curLoca.second + dx[i]] = true;
                q.push({ {curLoca.first + dy[i], curLoca.second + dx[i]}, curLevel + 1 });
                v[curLoca.first + dy[i]][curLoca.second + dx[i]] = curLevel + 1;
            }
        }
    }

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < N; col++) {
            if (!isVisited[row][col]) cout << -1 << ' ';
            else cout << v[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}