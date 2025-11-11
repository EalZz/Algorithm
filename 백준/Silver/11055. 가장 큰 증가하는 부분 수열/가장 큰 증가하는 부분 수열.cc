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

int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n), dp(n + 1);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        dp[i] = v[i];
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }

    int ans = 0;
    for (auto& i : dp) ans = max(ans, i);

    cout << ans;

    return 0;
}

