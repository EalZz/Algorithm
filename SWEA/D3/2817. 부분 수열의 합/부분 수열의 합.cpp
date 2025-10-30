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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, K; cin >> N >> K;

        int dp[1001] = { 0, };
        dp[0] = 1;

        while (N--) {
            int num; cin >> num;

            for (int i = K; i >= num; i--) dp[i] += dp[i - num];
        }

        cout << "#" << t << ' ' << dp[K] << '\n';
    }
    return 0;
}