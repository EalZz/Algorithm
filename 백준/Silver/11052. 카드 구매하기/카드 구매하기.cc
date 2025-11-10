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

    for (int w = 1; w <= N; w++) {
        int v; cin >> v;
        for (int i = w; i <= N; i++) dp[i] = max(dp[i], dp[i - w] + v);
    }

    cout << dp[N];

    return 0;
}