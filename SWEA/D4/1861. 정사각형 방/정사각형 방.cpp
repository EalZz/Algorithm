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

int dfs(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;
        
        int N; cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) cin >> v[row][col];
        }

        int ans = 0, node = 1e9;
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                int cnt = dfs(row, col, dp, v);
                if (cnt > ans) {
                    ans = cnt;
                    node = v[row][col];
                }
                else if (cnt == ans && v[row][col] < node) node = v[row][col];
            }
        }

        cout << "#" << t << " ";
        cout << node << ' ' << ans;
        cout << '\n';
    }
    return 0;
}

int dfs(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& v) {
    if (dp[row][col] != 0) return dp[row][col];

    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };
    int cnt = 1;

    for (int i = 0; i < 4; i++) {
        int nrow = row + dy[i];
        int ncol = col + dx[i];

        if (nrow >= v.size() || ncol >= v.size() || nrow < 0 || ncol < 0) continue;
        if (v[nrow][ncol] != v[row][col] + 1) continue;

        cnt = max(cnt, dfs(nrow, ncol, dp, v) + 1);
    }
    
    return dp[row][col] = cnt;
}