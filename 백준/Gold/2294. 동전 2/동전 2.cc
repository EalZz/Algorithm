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

    int n, k; cin >> n >> k;
    vector<int> dp(k + 1, 1e9);

    dp[0] = 0;
    while (n--) {
        int v; cin >> v;
        for (int i = v; i <= k; i++) dp[i] = min(dp[i], dp[i - v] + 1);
    }

    if (dp[k] == 1e9) cout << -1;
    else cout << dp[k];

    return 0;
}