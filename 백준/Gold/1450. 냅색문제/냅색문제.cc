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

void dfs(int s, int e, int C, long long sum, vector<long long>& ans, vector<long long>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, C; cin >> N >> C;
    vector<long long> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    vector<long long> ans1, ans2;
    dfs(0, N / 2 - 1, C, 0, ans1, v);
    dfs(N / 2, N - 1, C, 0, ans2, v);
    sort(ans2.begin(), ans2.end());

    long long ans = 0;
    for (int i = 0; i < ans1.size(); i++) ans += upper_bound(ans2.begin(), ans2.end(), C - ans1[i]) - ans2.begin();
    
    cout << ans;

    return 0;
}

void dfs(int s, int e, int C, long long sum, vector<long long>& ans, vector<long long>& v) {
    if (sum > C) return;
    if (s > e) {
        ans.push_back(sum);
        return;
    }

    dfs(s + 1, e, C, sum, ans, v);
    dfs(s + 1, e, C, sum + v[s], ans, v);
}
