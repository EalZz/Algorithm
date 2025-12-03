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
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long MOD = 1000000009;
    vector<long long> dp(1000001, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 1000000; i++) dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << dp[n] % MOD << '\n';
    }

    return 0;
}
