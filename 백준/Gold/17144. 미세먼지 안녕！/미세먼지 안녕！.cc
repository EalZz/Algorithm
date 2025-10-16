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
long long memo[10001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    vector<vector<int>> v(a, vector<int>(b));
    pair<int, int> air1 = { -1, -1 }, air2 = { -1, -1 };

    for (int row = 0; row < a; row++) {
        for (int col = 0; col < b; col++) {
            cin >> v[row][col];
            if (v[row][col] == -1) {
                if (air1.first == -1) air1 = { row, col };
                else air2 = { row, col };
            }
        }
    }

    while (c--) {
        vector<vector<int>> tmp(a, vector<int>(b, 0));
        for (int row = 0; row < a; row++) {
            for (int col = 0; col < b; col++) {
                if (v[row][col] <= 0) {
                    tmp[row][col] += v[row][col];
                    continue;
                }

                int spread = v[row][col] / 5;
                int count = 0;
                int dy[4] = { 1, -1, 0, 0 };
                int dx[4] = { 0, 0, 1, -1 };

                for (int i = 0; i < 4; i++) {
                    int ny = row + dy[i];
                    int nx = col + dx[i];
                    if (ny < 0 || nx < 0 || ny >= a || nx >= b) continue;
                    if (v[ny][nx] == -1) continue;

                    tmp[ny][nx] += spread;
                    count++;
                }
                tmp[row][col] += v[row][col] - spread * count;
            }
        }

        v = tmp;
        v[air1.first][air1.second] = -1;
        v[air2.first][air2.second] = -1;

        for (int i = air1.first - 1; i > 0; i--) v[i][0] = v[i - 1][0];
        for (int i = 0; i < b - 1; i++) v[0][i] = v[0][i + 1];
        for (int i = 0; i < air1.first; i++) v[i][b - 1] = v[i + 1][b - 1];
        for (int i = b - 1; i > 1; i--) v[air1.first][i] = v[air1.first][i - 1];
        v[air1.first][1] = 0;

        for (int i = air2.first + 1; i < a - 1; i++) v[i][0] = v[i + 1][0];
        for (int i = 0; i < b - 1; i++) v[a - 1][i] = v[a - 1][i + 1];
        for (int i = a - 1; i > air2.first; i--) v[i][b - 1] = v[i - 1][b - 1];
        for (int i = b - 1; i > 1; i--) v[air2.first][i] = v[air2.first][i - 1];
        v[air2.first][1] = 0;
    }

    int sum = 0;
    for (int row = 0; row < a; row++) {
        for (int col = 0; col < b; col++) {
            if (v[row][col] > 0) sum += v[row][col];
        }
    }

    cout << sum;
    return 0;
}
