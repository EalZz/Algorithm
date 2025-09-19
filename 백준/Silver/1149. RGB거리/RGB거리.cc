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
//int memo[21][21][21];
//long long memo[101];
int memo[1001][4];

int dfs(int level, int before, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(4, -1));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T; row++) {
        for (int col = 1; col <= 3; col++) cin >> v[row][col];
    }

    cout << dfs(0, 0, v);

    return 0;
}

int dfs(int level, int before, vector<vector<int>>& v) {
    if (memo[level][before] != -1) return memo[level][before];

    if (level == v.size()) return 0;

    int sum = 1e9;
    if (before == 0) {
        for (int i = 1; i <= 3; i++) sum = min(sum, v[level][i] + dfs(level + 1, i, v));
    }
    else {
        for (int i = 1; i <= 3; i++) {
            if (i == before) continue;
            sum = min(sum, v[level][i] + dfs(level + 1, i, v));
        }
    }
    memo[level][before] = sum;
    return memo[level][before];
}
