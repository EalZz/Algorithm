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
int memo[21][21][21];
//int memo[10000001];
void dfs(int y, int x, vector<vector<int>>& matrix, vector<vector<bool>>& isVisited, int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int asdf = 0; cin >> asdf;
    while (asdf--) {
        cnt = 0;
        //int T = 0; cin >> T;
        //int N = 0; cin >> N;
        int a = 0, b = 0, c = 0; cin >> a >> b >> c;
        //vector<int> v;
        //vector<int> tmp;
        //vector<vector<int>> v(T, vector<int>(N));
        vector<vector<int>> matrix(b, vector<int>(a, 0));
        vector<vector<bool>> isVisited(b, vector<bool>(a, false));
        while (c--) {
            int x = 0, y = 0;
            cin >> x >> y;
            matrix[y][x] = 1;
        }

        for (int row = 0; row < b; row++) {
            for (int col = 0; col < a; col++) {
                if (!isVisited[row][col] && matrix[row][col] == 1) {
                    cnt++;
                    isVisited[row][col] = true;
                    dfs(row, col, matrix, isVisited, a, b);
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}

void dfs(int y, int x, vector<vector<int>>& matrix, vector<vector<bool>>& isVisited, int a, int b) {
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < a && ny < b && matrix[ny][nx] == 1 && !isVisited[ny][nx]) {
            isVisited[ny][nx] = true;
            dfs(ny, nx, matrix, isVisited, a, b);
        }
    }
    return;
}