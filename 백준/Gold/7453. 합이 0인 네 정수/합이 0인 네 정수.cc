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
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<vector<int>> v(4, vector<int>(N));
    for (int col = 0; col < N; col++) {
        for (int row = 0; row < 4; row++) cin >> v[row][col];
    }

    vector<long long> sum01;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) sum01.push_back(v[0][i] + v[1][j]);
    }
    sort(sum01.begin(), sum01.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            long long tmp = -(v[2][i] + v[3][j]);
            ans += upper_bound(sum01.begin(), sum01.end(), tmp) - lower_bound(sum01.begin(), sum01.end(), tmp);
        }
    }
    cout << ans;

    return 0;
}