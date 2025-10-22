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

    vector<int> lcs, idx(N, 0), trace(N, -1), lastidx;
    lcs.push_back(v[0].second);
    lastidx.push_back(0);

    for (int i = 1; i < N; i++) {
        int val = v[i].second;
        int pos = lower_bound(lcs.begin(), lcs.end(), val) - lcs.begin();

        if (pos == lcs.size()) {
            lcs.push_back(val);
            lastidx.push_back(i);
        }
        else {
            lcs[pos] = val;
            lastidx[pos] = i;
        }

        idx[i] = pos;

        if (pos > 0) trace[i] = lastidx[pos - 1];
    }

    int len = lcs.size();
    cout << N - lcs.size() << '\n';

    vector<int> ans;
    int cur = lastidx[len - 1];
    while (cur >= 0) {
        ans.push_back(cur);
        cur = trace[cur];
    }
    reverse(ans.begin(), ans.end());

    vector<bool> isLcs(N, false);
    for (int a : ans) isLcs[a] = true;
    for (int i = 0; i < N; i++) {
        if (!isLcs[i]) cout << v[i].first << '\n';
    }

    return 0;
}
