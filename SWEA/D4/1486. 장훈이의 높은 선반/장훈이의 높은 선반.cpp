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

void dfs(int idx, int sum, int B, int& ans, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;
        
        int N, B; cin >> N >> B;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];

        int ans = 1e9;
        dfs(0, 0, B, ans, v);

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}

void dfs(int idx, int sum, int B, int& ans, vector<int>& v) {
    if (idx == v.size()) {
        if (sum >= B) ans = min(ans, sum - B);
        return;
    }

    dfs(idx + 1, sum, B, ans, v);
    sum += v[idx];
    dfs(idx + 1, sum, B, ans, v);

    return;
}