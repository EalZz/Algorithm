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

void dfs(int idx, vector<int> ans, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    while (cin >> N) {
        vector<int> v(N), ans;
        for (int i = 0; i < N; i++) cin >> v[i];

        dfs(0, ans, v);
        cout << '\n';
    }

    return 0;
}

void dfs(int idx, vector<int> ans, vector<int>& v) {
    if (ans.size() + v.size() - idx < 6) return;

    if (ans.size() == 6) {
        for (int i = 0; i < 6; i++) cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = idx; i < v.size(); i++) {
        ans.push_back(v[i]);
        dfs(i + 1, ans, v);
        ans.pop_back();
    }
    return;
}