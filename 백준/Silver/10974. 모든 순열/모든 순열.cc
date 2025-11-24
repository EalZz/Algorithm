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

void dfs(int N, vector<int>& ans, vector<bool> isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<bool> isVisited(N + 1, false);
    vector<int> ans;

    dfs(N, ans, isVisited);

    return 0;
}

void dfs(int N, vector<int>& ans, vector<bool> isVisited) {
    if (ans.size() == N) {
        for (auto& a : ans) cout << a << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (isVisited[i]) continue;

        isVisited[i] = true;
        ans.push_back(i);

        dfs(N, ans, isVisited);

        isVisited[i] = false;
        ans.pop_back();
    }
    return;
}