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
int cnt = 0, cnt1 = 0;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[1001];
int memo[2][100001];

void dfs(int N, vector<int>& v, vector<int>& result, vector<bool>& isVisited, set<vector<int>>& s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(2, vector<int>(T));
    vector<bool> isVisited(T, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        int N; cin >> N;
        vector<vector<int>> v(2, vector<int>(N + 1));
        for (int row = 0; row < 2; row++) {
            for (int col = 1; col <= N; col++) cin >> v[row][col];
        }

        memo[0][0] = 0;
        memo[1][0] = 0;
        memo[0][1] = v[0][1];
        memo[1][1] = v[1][1];

        for (int i = 2; i <= N; i++) {
            memo[0][i] = v[0][i] + max(memo[1][i - 2], memo[1][i - 1]);
            memo[1][i] = v[1][i] + max(memo[0][i - 2], memo[0][i - 1]);
        }
        cout << max(memo[0][N], memo[1][N]) << '\n';
    }

    return 0;
}