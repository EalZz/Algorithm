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
int cnt = 0;
int ans = -1;

void dfs(int a, int b, vector<vector<int>>& edge, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int a, b; cin >> a >> b;

    int m; cin >> m;
    vector<vector<int>> edge(N + 1);
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }

    vector<bool> isVisited(N + 1, false);
    isVisited[a] = true;
    dfs(a, b, edge, isVisited);
    
    cout << ans;

    return 0;
}

void dfs(int a, int b, vector<vector<int>>& edge, vector<bool>& isVisited) {
    if (a == b) {
        ans = cnt;
        return;
    }

    for (int i = 0; i < edge[a].size(); i++) {
        if (isVisited[edge[a][i]]) continue;

        isVisited[edge[a][i]] = true;
        cnt++;

        dfs(edge[a][i], b, edge, isVisited);

        isVisited[edge[a][i]] = false;
        cnt--;
    }

    return;
}