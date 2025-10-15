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
//int memo[1001][3];
//long long memo[1000001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

vector<vector<long long>> power(int N, long long M, vector<vector<long long>>& v);
vector<vector<long long>> mul(int N, int mod, vector<vector<long long>>& a, vector<vector<long long>>& b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    long long M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    vector<vector<long long>> v(N, vector<long long>(N));
    //vector<bool> isVisited(4000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) cin >> v[row][col];
    }

    vector<vector<long long>> ans = power(N, M, v);

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) cout << ans[row][col] % 1000 << ' ';
        cout << '\n';
    }

    return 0;
}

vector<vector<long long>> power(int N, long long M, vector<vector<long long>>& v) {
    if (M == 1) return v;

    vector<vector<long long>> half = power(N, M / 2, v);
    vector<vector<long long>> ans = mul(N, 1000, half, half);

    if (M % 2) ans = mul(N, 1000, ans, v);

    return ans;
}

vector<vector<long long>> mul(int N, int mod, vector<vector<long long>>& a, vector<vector<long long>>& b) {
    vector<vector<long long>> tmp(N, vector<long long>(N));
    for (int rowa = 0; rowa < N; rowa++) {
        for (int colb = 0; colb < N; colb++) {
            for (int com = 0; com < N; com++) tmp[rowa][colb] += (a[rowa][com] * b[com][colb]) % mod;
        }
    }

    return tmp;
}
