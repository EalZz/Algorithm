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

    int N, K; cin >> N >> K;
    
    vector<int> dp(K + 1, 0);
    while (N--) {
        int W, V; cin >> W >> V;
        for (int i = K; i >= W; i--) dp[i] = max(dp[i], dp[i - W] + V);
    }

    cout << dp[K];

    return 0;
}