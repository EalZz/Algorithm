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
//long long memo[101][10];
long long memo[100001];
//long long MOD = 1000000000;

int dfs(int node, int p, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int M = 0; cin >> M;
    //int N = 0; cin >> N;
    int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<long long> v(T + 1, 0);
    vector<vector<int>> v(a + 1);
    vector<bool> isVisited(a + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < a - 1; i++) {
        int s, e; cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    fill(memo, memo + a + 1, 0);
    dfs(b, 0, v);

    for (int i = 0; i < c; i++) {
        int tmp; cin >> tmp;
        cout << memo[tmp] << '\n';
    }

    return 0;
}

int dfs(int node, int p, vector<vector<int>>& v) {
    int count = 1;

    for (int i = 0; i < v[node].size(); i++) {
        if (v[node][i] == p) continue;
        count += dfs(v[node][i], node, v);
    }

    memo[node] = count;
    return memo[node];
}