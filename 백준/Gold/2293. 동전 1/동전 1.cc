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

    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = v[i]; j <= k; j++) dp[j] += dp[j - v[i]];
    }

    cout << dp[k];

    return 0;
}