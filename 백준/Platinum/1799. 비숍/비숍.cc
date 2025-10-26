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

void queen(int N, int row, int col, int count, int color, vector<int>& vcolor, vector<vector<int>> v, vector<bool>& diag1, vector<bool>& diag2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    vector<vector<int>> v(N, vector<int>(N));
    vector<int> vcolor(2);
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) cin >> v[row][col];
    }

    vector<bool> diag1(2 * N - 1, false);
    vector<bool> diag2(2 * N - 1, false);

    queen(N, 0, 0, 0, 0, vcolor, v, diag1, diag2);
    queen(N, 0, 0, 0, 1, vcolor, v, diag1, diag2);
    cout << vcolor[0] + vcolor[1];

    return 0;
}

void queen(int N, int row, int col, int count, int color, vector<int>& vcolor, vector<vector<int>> v, vector<bool>& diag1, vector<bool>& diag2) {
    if (col >= N) {
        row++;
        col = 0;
    }
    if (row == N) {
        vcolor[color] = max(vcolor[color], count);
        return;
    }

    if (v[row][col] && (row + col) % 2 == color && !diag1[row - col + N - 1] && !diag2[row + col]) {
        diag1[row - col + N - 1] = true;
        diag2[row + col] = true;

        queen(N, row, col + 1, count + 1, color, vcolor, v, diag1, diag2);

        diag1[row - col + N - 1] = false;
        diag2[row + col] = false;
    }
    queen(N, row, col + 1, count, color, vcolor, v, diag1, diag2);
}