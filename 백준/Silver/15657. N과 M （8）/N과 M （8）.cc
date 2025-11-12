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
#include <list>

using namespace std;

void dfs(int idx, int cnt, int M, vector<int>& ans, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> ans;
    dfs(0, 0, M, ans, v);

    return 0;
}

void dfs(int idx, int cnt, int M, vector<int>& ans, vector<int>& v) {
    if (cnt == M) {
        for (auto& a : ans) cout << a << ' ';
        cout << '\n';
        return;
    }

    if (idx == v.size()) return;

    for (int i = idx; i < v.size(); i++) {
        ans.push_back(v[i]);
        dfs(i, cnt + 1, M, ans, v);
        ans.pop_back();
    }
    return;
}