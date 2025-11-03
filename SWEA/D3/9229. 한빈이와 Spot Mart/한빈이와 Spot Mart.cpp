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

using namespace std;
int ans = -1;

void dfs(int idx, int cnt, int sum, int limit, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int N, M; cin >> N >> M;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.end());

        ans = -1;
        dfs(0, 0, 0, M, v);

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}

void dfs(int idx, int cnt, int sum, int limit, vector<int>& v) {
    if (sum > limit) return;
    if (cnt == 2) {
        ans = max(ans, sum);
        return;
    }
    if (idx >= v.size()) return;

    dfs(idx + 1, cnt, sum, limit, v);
    dfs(idx + 1, cnt + 1, sum + v[idx], limit, v);
}