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
long long memo[501][501];
//long long MOD = 1000000000;
//int memo[1000001][5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    vector<pair<int, int>> v(N + 1, {0, 0});
    for (int i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        v[i] = { a, b };
    }

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) memo[i][j] = 1e15;
    }
    for (int i = 1; i <= N; i++) memo[i][i] = 0;

    for (int len = 1; len < N; len++) {
        for (int i = 1; i + len <= N; i++) {
            int j = i + len;
            for (int k = i; k < j; k++)
                memo[i][j] = min(memo[i][j], memo[i][k] + memo[k + 1][j] + v[i].first * v[k].second * v[j].second);
        }
    }

    cout << memo[1][N];

    return 0;
}