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

void dfs(int L, int idx, int cnt1, int cnt2, string pwd, vector<char>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L, C; cin >> L >> C;
    vector<char> v(C);
    for (int i = 0; i < C; i++) cin >> v[i];
    sort(v.begin(), v.end());

    dfs(L, 0, 0, 0, "", v);

    return 0;
}

void dfs(int L, int idx, int cnt1, int cnt2, string pwd, vector<char>& v) {
    if (idx >= v.size()) {
        if (pwd.size() != L || cnt1 < 1 || cnt2 < 2) return;
        cout << pwd << '\n';
        return;
    }

    if (v[idx] == 'a' || v[idx] == 'e' || v[idx] == 'i' || v[idx] == 'o' || v[idx] == 'u')
        dfs(L, idx + 1, cnt1 + 1, cnt2, pwd + v[idx], v);
    else dfs(L, idx + 1, cnt1, cnt2 + 1, pwd + v[idx], v);

    dfs(L, idx + 1, cnt1, cnt2, pwd, v);

    return;
}