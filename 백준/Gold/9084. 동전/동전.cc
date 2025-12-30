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

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<int> coin(N);
        for (int i = 0; i < N; i++) cin >> coin[i];
		int target; cin >> target;

        int dp[10001] = { 0, };
        dp[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = coin[i]; j <= target; j++)  dp[j] += dp[j - coin[i]];;
        }
        cout << dp[target] << '\n';
    }

    return 0;
}