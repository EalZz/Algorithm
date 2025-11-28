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

    vector<vector<int>> dp(N + 1, vector<int>(2, 0));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
        dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % 9901;
    }

    cout << (dp[N][1] + dp[N][0] * 2) % 9901;

    return 0;
}