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
//int memo[1001][3];
//long long memo[1000001];
//long long MOD = 1000000000;
int memo[1000001][5][5];

int dfs(int idx, int lf, int rf, vector<int>& v);
int calc(int a, int b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N; cin >> N;
    //int M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<vector<int>> v(N);
    //vector<bool> isVisited(4000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    memset(memo, -1, sizeof(memo));

    vector<int> v;
    v.push_back(0);
    int tmp;
    while (cin >> tmp && tmp != 0) v.push_back(tmp);

    cout << dfs(0, 0, 0, v);

    return 0;
}

int dfs(int idx, int lf, int rf, vector<int>& v) {
    if (idx == v.size() - 1) return 0;

    if (memo[idx][lf][rf] != -1) return memo[idx][lf][rf];

    int left = dfs(idx + 1, v[idx + 1], rf, v) + calc(lf, v[idx + 1]);
    int right = dfs(idx + 1, lf, v[idx + 1], v) + calc(rf, v[idx + 1]);

    return memo[idx][lf][rf] = min(left, right);
}

int calc(int a, int b) {
    if (a == b) return 1;
    if (a == 0) return 2;

    if (abs(a - b) == 2) return 4;
    return 3;
}