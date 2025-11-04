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
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int N, K; cin >> N >> K;
        int dp[1001];
        fill(dp, dp + 1001, 0);

        while (N--) {
            int weight, value;
            cin >> weight >> value;

            for (int i = K; i >= weight; i--) dp[i] = max(dp[i], dp[i - weight] + value);
        }
       
        cout << "#" << t << " ";
        cout << dp[K];
        cout << '\n';
    }
    return 0;
}