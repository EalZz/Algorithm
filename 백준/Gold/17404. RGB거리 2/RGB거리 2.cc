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
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
int memo[1001][3];
//long long memo[100001];
//long long MOD = 1000000000;

int dfs(int idx, int pre, int first, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    //int M = 0; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<long long> v(T + 1, 0);
    vector<vector<int>> v(N, vector<int>(3, -1));
    //vector<bool> isVisited(a + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < 3; col++) cin >> v[row][col];
    }

    int result = 1e9;
    for (int i = 0; i < 3; i++) {
        memset(memo, -1, sizeof(memo));
        memo[0][i] = v[0][i];
        result = min(result, dfs(1, i, i, v) + v[0][i]);
    }

    cout << result;

    return 0;
}

int dfs(int level, int pre, int first, vector<vector<int>>& v) {
    if (level == v.size()) {
        if (pre == first) return 1e9;
        return 0;
    }

    if (memo[level][pre] != -1) return memo[level][pre];

    int sum = 1e9;
    for (int i = 0; i < 3; i++) {
        if (i == pre) continue;
        sum = min(sum, v[level][i] + dfs(level + 1, i, first, v));
    }

    memo[level][pre] = sum;
    return memo[level][pre];
}