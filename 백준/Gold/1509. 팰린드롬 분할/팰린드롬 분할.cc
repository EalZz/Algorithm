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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str; cin >> str;

    bool isPalin[2500][2500];
    int dp[2500];
    fill(dp, dp + 2500, 1e9);

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; i + j < str.size(); j++) {
            if (i == 0) {
                isPalin[j][i + j] = true;
                continue;
            }
            if (str[j] == str[i + j] && (i == 1 || isPalin[j + 1][i + j - 1])) isPalin[j][j + i] = true;
        }
    }

    for (int i = 0; i < str.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (isPalin[j][i]) {
                if (j == 0) {
                    dp[i] = 1;
                    break;
                }
                dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }

    cout << dp[str.size() - 1];

    return 0;
}
