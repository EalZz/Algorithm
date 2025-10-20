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
long long MOD = 1000000007;
//int memo[1000001][5][5];

long long sum(long long N, long long exp);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    long long ans = 0;
    while (T--) {
        long long N, S; cin >> N >> S;
        ans += (S * sum(N, MOD - 2) % MOD) % MOD;
    }

    cout << ans % MOD;

    return 0;
}

long long sum(long long N, long long exp) {
    if (exp == 0) return 1;
    if (exp % 2 == 1) return N * sum(N, exp - 1) % MOD;

    long long half = sum(N, exp / 2);
    
    return half * half % MOD;
}