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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    vector<pair<int, int>> v(N + 1);
    for (int i = 1; i <= N; i++) cin >> v[i].first >> v[i].second;

    int dp[20];
    fill(dp, dp + 20, 0);

    for (int i = 1; i <= N + 1; i++) {
        dp[i] = max(dp[i], dp[i - 1]);

        if (i <= N) {
            int curCost = v[i].first;
            int curValue = v[i].second;

            if (i + curCost <= N + 1) dp[i + curCost] = max(dp[i + curCost], dp[i] + curValue);
        }
    }
    int ans = max(dp[N], dp[N + 1]);

    cout << ans;

    return 0;
}