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

bool dfs(int node, vector<vector<int>>& edge, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        int tc; cin >> tc;
        
        int N; cin >> N;
        vector<vector<int>> edge(100);
        vector<bool> isVisited(100, false);
        for (int i = 0; i < N; i++) {
            int start, end; cin >> start >> end;
            edge[start].push_back(end);
        }
        
        cout << "#" << t << " ";
        if (dfs(0, edge, isVisited)) cout << 1;
        else cout << 0;
        cout << '\n';
    }
    return 0;
}

bool dfs(int node, vector<vector<int>>& edge, vector<bool>& isVisited) {
    if (node == 99) return true;
    isVisited[node] = true;

    for (auto next : edge[node]) {
        if (isVisited[next]) continue;
        if (dfs(next, edge, isVisited)) return true;
    }

    return false;
}