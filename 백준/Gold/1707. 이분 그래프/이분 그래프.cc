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

void dfs(int node, vector<vector<int>>& edge, vector<int>& check);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int V, E; cin >> V >> E;
        vector<vector<int>> edge(V + 1);
        vector<int> check(V + 1, 0);

        for (int i = 0; i < E; i++) {
            int u, v; cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
        }

        for (int i = 1; i <= V; i++) {
            if (check[i] != 0) continue;
            dfs(i, edge, check);
        }

        bool isBianryg = true;
        for (int i = 1; i <= V; i++) {
            for (int j = 0; j < edge[i].size(); j++) {
                if (check[i] != check[edge[i][j]]) continue;
                isBianryg = false;
                break;
            }
            if (!isBianryg) break;
        }

        if (isBianryg) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}

void dfs(int node, vector<vector<int>>& edge, vector<int>& check) {
    if (check[node] == 0)  check[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        if (check[edge[node][i]] != 0) continue;

        if (check[node] == 1) check[edge[node][i]] = 2;
        else check[edge[node][i]] = 1;

        dfs(edge[node][i], edge, check);
    }

    return;
}