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

void dfs(int idx, int M, set<vector<int>>& s, vector<int>& ans, vector<int>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<int> v(N);
    vector<bool> isVisited(N, false);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    vector<int> ans;
    set<vector<int>> s;
    dfs(0, M, s, ans, v, isVisited);

    for (auto& v : s) {
        for (auto& i : v) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}

void dfs(int idx, int M, set<vector<int>>& s, vector<int>& ans, vector<int>& v, vector<bool>& isVisited) {
    if (ans.size() == M) {
        s.insert(ans);
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        if (isVisited[i]) continue;

        ans.push_back(v[i]);
        isVisited[i] = true;

        dfs(i, M, s, ans, v, isVisited);

        ans.pop_back();
        isVisited[i] = false;
    }
    true;
}