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
//int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];
int memo[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    vector<int> lcs;
    lcs.push_back(v[0].second);
    for (int i = 1; i < N; i++) {
        if (lcs.back() < v[i].second) lcs.push_back(v[i].second);
        else {
            int idx = lower_bound(lcs.begin(), lcs.end(), v[i].second) - lcs.begin();
            lcs[idx] = v[i].second;
        }
    }

    cout << N - lcs.size();

    return 0;
}
