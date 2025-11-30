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

void dfs(int node, vector<int>& edge, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    while (tc--) {
        int N; cin >> N;

        vector<int> edge(N + 1, 0);
        vector<bool> isVisited(N + 1, false);
        for (int i = 1; i <= N; i++) cin >> edge[i];

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            if (isVisited[i]) continue;

            isVisited[i] = true;
            dfs(edge[i], edge, isVisited);
            cnt++;
        }

        cout << cnt << '\n';
    }

    return 0;
}

void dfs(int node, vector<int>& edge, vector<bool>& isVisited) {
    if (isVisited[node]) return;

    isVisited[node] = true;
    dfs(edge[node], edge, isVisited);

    return;
}