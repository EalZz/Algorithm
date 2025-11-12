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

    int N, M; cin >> N >> M;
    vector<int> dp(M + 1, 0);
    dp[0] = 1;

    while (N--) {
        int v; cin >> v;
        for (int i = v; i <= M; i++) dp[i] += dp[i - v];
    }

    cout << dp[M];

    return 0;
}