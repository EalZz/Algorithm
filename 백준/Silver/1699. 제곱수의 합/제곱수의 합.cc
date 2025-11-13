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
    
    int N; cin >> N;
    vector<int> dp(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        dp[i] = i;
        for (int j = 1; j * j <= i; j++) dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    cout << dp[N];

    return 0;
}