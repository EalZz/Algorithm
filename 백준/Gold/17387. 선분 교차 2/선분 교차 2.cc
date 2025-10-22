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

int ccw(pair<long long, long long> x, pair<long long, long long> y, pair<long long, long long> z);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    pair<long long, long long> A1, A2, B1, B2;
    cin >> A1.first >> A1.second
        >> A2.first >> A2.second
        >> B1.first >> B1.second
        >> B2.first >> B2.second;

    int ccw1 = ccw(A1, A2, B1) * ccw(A1, A2, B2);
    int ccw2 = ccw(B1, B2, A1) * ccw(B1, B2, A2);

    if (ccw1 == 0 && ccw2 == 0) {
        if (A1 > A2) swap(A1, A2);
        if (B1 > B2) swap(B1, B2);
        if (A2 >= B1 && A1 <= B2) cout << 1;
        else cout << 0;
    }
    else if (ccw1 <= 0 && ccw2 <= 0) cout << 1;
    else cout << 0;

    return 0;
}

int ccw(pair<long long, long long> x, pair<long long, long long> y, pair<long long, long long> z) {
    long long ans = 0;
    ans = (x.first * y.second + y.first * z.second + z.first * x.second)
        - (x.second * y.first + y.second * z.first + z.second * x.first);

    if (ans > 0) return 1;
    if (ans == 0)return 0;
    return -1;
}