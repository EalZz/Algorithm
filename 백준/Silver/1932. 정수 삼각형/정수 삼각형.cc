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
long memo[501][501];

int dfs(int level, int idx, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T, 0));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int tmpidx = 1;
    for (int row = 0; row < T; row++) {
        for (int col = 0; col < tmpidx; col++) cin >> v[row][col];
        tmpidx++;
    }

    cout << dfs(0, 0, v);

    return 0;
}

int dfs(int level, int idx, vector<vector<int>>& v) {
    if (memo[level][idx] != -1) return memo[level][idx];

    if (level == v.size() - 1) return v[level][idx];
    
    memo[level][idx] = v[level][idx] + max(dfs(level + 1, idx, v), dfs(level + 1, idx + 1, v));

    return memo[level][idx];
}
