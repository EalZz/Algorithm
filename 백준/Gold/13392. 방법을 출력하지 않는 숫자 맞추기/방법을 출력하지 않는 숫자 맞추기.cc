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
int dp[10000][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    string ss, se; cin >> ss >> se;

    vector<int> s(N), e(N);
    for (int i = 0; i < N; i++) {
        s[i] = ss[i] - '0';
        e[i] = se[i] - '0';
    }

    for (int i = 0; i < N; i++) fill(dp[i], dp[i] + 10, 1e9);
    

    for (int i = 0; i < 10; i++) dp[0][i] = ((s[0] + i) % 10 - e[0] + 10) % 10 + i;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int next = (s[i] + j + k) % 10;
                dp[i][(j + k) % 10] = min(dp[i][(j + k) % 10], dp[i - 1][j] + (next - e[i] + 10) % 10 + k);
            }
        }
    }

    int ans = 1e9;
    for (int i = 0; i < 10; i++) ans = min(ans, dp[N - 1][i]);

    cout << ans;

    return 0;
}