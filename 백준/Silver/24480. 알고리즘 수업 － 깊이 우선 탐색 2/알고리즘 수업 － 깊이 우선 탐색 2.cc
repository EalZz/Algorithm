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

int cnt = 1;

void dfs(int node, vector<int>& ans, vector<vector<int>>& edge, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, R; cin >> N >> M >> R;

    vector<vector<int>> edge(N + 1);
    vector<int> ans(N + 1, 0);
    vector<bool> isVisited(N + 1, false);
    for (int i = 0; i < M; i++) {
        int start, end; cin >> start >> end;
        edge[start].push_back(end);
        edge[end].push_back(start);
    }

    for (auto& e : edge) sort(e.rbegin(), e.rend());
    ans[R] = 1;
    isVisited[R] = true;
    dfs(R, ans, edge, isVisited);

    for (int i = 1; i <= N; i++) cout << ans[i] << '\n';

    return 0;
}

void dfs(int node, vector<int>& ans, vector<vector<int>>& edge, vector<bool>& isVisited) {
    for (auto& next : edge[node]) {
        if (isVisited[next]) continue;

        isVisited[next] = true;
        ans[next] = ++cnt;
        dfs(next, ans, edge, isVisited);
    }

    return;
}