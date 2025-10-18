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
long long memo[10001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int M; cin >> M;
    vector<int> v(M);
    for (int i = 0; i < M; i++) cin >> v[i];
    sort(v.begin(), v.end());

    long long price = 0, ans = 0;
    for (int i = 0; i < M; i++) {
        if ((v[i] * min(N, M - i)) >= ans) {
            ans = v[i] * min(N, M - i);
            price = v[i];
        }
    }
    cout << price << ' ' << ans;
}