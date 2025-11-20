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

    int N; cin >> N;
    vector<int> v(N), dp(N, 0);
    for (int i = 0; i < N; i++) cin >> v[i];

    for (int i = 0; i < N; i++) {
        dp[i] = v[i];
        for (int j = 0; j <= i; j++) {
            if(v[j] < v[i]) dp[i] = max(dp[i], dp[j] + v[i]);
        }
    }

    int ans = 0;
    for (auto& d : dp) ans = max(ans, d);
    cout << ans;

    return 0;
}