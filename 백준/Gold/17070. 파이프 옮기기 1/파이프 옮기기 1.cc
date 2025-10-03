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
int cnt = 0, cnt1 = 0;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];
long long memo[10001];

void dfs(int y, int x, int state, vector<vector<int>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T + 1, false);
    vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) cin >> v[row][col];
    }

    dfs(0, 1, 1, v, isVisited);
    cout << cnt;

    return 0;
}

void dfs(int y, int x, int state, vector<vector<int>>& v, vector<vector<bool>>& isVisited) {
    if (y == v.size() - 1 && x == v.size() - 1) {
        cnt++;
        return;
    }

    int dy[3] = { 1, 0, 1 };
    int dx[3] = { 0, 1, 1 };

    for (int i = 0; i < 3; i++) {
        if ((state == 0 && i == 1) || (state == 1 && i == 0)) continue;

        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= v.size() || nx >= v.size() || isVisited[ny][nx]) continue;
        if (i != 2) {
            if (v[ny][nx] == 1) continue;
            isVisited[ny][nx] = true;
            dfs(ny, nx, i, v, isVisited);
            isVisited[ny][nx] = false;
        }
        else {
            if (v[ny][nx] == 1 || v[ny][nx - 1] == 1 || v[ny - 1][nx] == 1) continue;
            isVisited[ny][nx] = true;
            dfs(ny, nx, i, v, isVisited);
            isVisited[ny][nx] = false;
        }
    }
    return;
}