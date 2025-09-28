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
//long long memo[1001];
//int memo[101][4];

void dfs(char color, int row, int col, vector<vector<char>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    vector<vector<char>> v(T, vector<char>(T, 0));
    vector<vector<char>> v1(T, vector<char>(T, 0));
    vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) {
            cin >> v[row][col];
            if (v[row][col] == 'G') v1[row][col] = 'R';
            else v1[row][col] = v[row][col];
        }
    }

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) {
            if (!isVisited[row][col]) {
                isVisited[row][col] = true;
                cnt++;
                dfs(v[row][col], row, col, v, isVisited);
            }
        }
    }

    isVisited.assign(T, vector<bool>(T, false));
    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) {
            if (!isVisited[row][col]) {
                isVisited[row][col] = true;
                cnt1++;
                dfs(v1[row][col], row, col, v1, isVisited);
            }
        }
    }

    cout << cnt << ' ' << cnt1;

    return 0;
}

void dfs(char color, int row, int col, vector<vector<char>>& v, vector<vector<bool>>& isVisited) {
    int dy[4] = {0, 0, 1, -1};
    int dx[4] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        if (row + dy[i] >= 0 && col + dx[i] >= 0 && row + dy[i] < v.size() && col + dx[i] < v.size()
            && v[row + dy[i]][col + dx[i]] == color && !isVisited[row + dy[i]][col + dx[i]]) {
            isVisited[row + dy[i]][col + dx[i]] = true;
            dfs(color, row + dy[i], col + dx[i], v, isVisited);
        }
    }
}