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
long long memo[50001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    vector<vector<char>> v(T, vector<char>(N, 0));
    vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string tmp = "";
    pair<int, int> start;
    vector<pair<int, int>> end;
    for (int row = 0; row < T; row++) {
        cin >> tmp;
        for (int col = 0; col < N; col++) {
            v[row][col] = tmp[col];
            if (tmp[col] == 'I') start = make_pair(row, col);
        }
    }

    queue<pair<int, int>> q;
    q.push({ start });
    isVisited[start.first][start.second] = true;

    int dy[4] = { 0, 0, 1, -1 };
    int dx[4] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        pair<int, int> curLoca = q.front();
        q.pop();

        if(v[curLoca.first][curLoca.second] == 'P') cnt++;

        for (int i = 0; i < 4; i++) {
            if (curLoca.first + dy[i] >= 0 && curLoca.second + dx[i] >= 0 && curLoca.first + dy[i] < T && curLoca.second + dx[i] < N
                && v[curLoca.first + dy[i]][curLoca.second + dx[i]] != 'X' && !isVisited[curLoca.first + dy[i]][curLoca.second + dx[i]]) {
                isVisited[curLoca.first + dy[i]][curLoca.second + dx[i]] = true;
                q.push({ curLoca.first + dy[i], curLoca.second + dx[i] });
            }
        }
    }

    if (cnt == 0) cout << "TT";
    else cout << cnt;

    return 0;
}
