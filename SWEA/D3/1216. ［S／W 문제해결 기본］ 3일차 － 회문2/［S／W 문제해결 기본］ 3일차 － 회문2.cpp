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
bool dp[101][101];

void isPelin(string& s, int start, int end);

int main() {
    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        int tc; cin >> tc;

        vector<string> v1(100), v2(100);
        for (int i = 0; i < 100; i++) {
            cin >> v1[i];
            for (int j = 0; j < 100; j++) v2[j].push_back(v1[i][j]);
        }

        int ans = 0;
        for (int row = 0; row < 100; row++) {
            for (int i = 0; i < 101; i++) fill(dp[i], dp[i] + 101, false);
            for (int len = 1; len <= 100; len++) {
                for (int start = 0; start + len - 1 < 100; start++) {
                    int end = start + len - 1;
                    isPelin(v1[row], start, end);
                    if (dp[start][end]) ans = max(ans, end - start + 1);
                }
            }
        }

        for (int row = 0; row < 100; row++) {
            for (int i = 0; i < 101; i++) fill(dp[i], dp[i] + 101, false);
            for (int len = 1; len <= 100; len++) {
                for (int start = 0; start + len - 1 < 100; start++) {
                    int end = start + len - 1;
                    isPelin(v2[row], start, end);
                    if (dp[start][end]) ans = max(ans, end - start + 1);
                }
            }
        }

        cout << "#" << tc << ' ' << ans << '\n';
    }
    return 0;
}

void isPelin(string& s, int start, int end) {
    if (start == end) dp[start][end] = true;
    else if (s[start] == s[end]) {
        if(end - start == 1) dp[start][end] = true;
        else if(dp[start + 1][end - 1]) dp[start][end] = true;
    }

    return;
}