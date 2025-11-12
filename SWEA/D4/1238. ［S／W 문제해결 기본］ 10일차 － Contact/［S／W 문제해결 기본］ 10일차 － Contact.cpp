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

void bfs(int start, vector<vector<int>>& edge, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;
        
        int N, M; cin >> N >> M;
        int n = N / 2;
        vector<vector<int>> edge(101);
        vector<bool> isVisited(101, false);
        while (n--) {
            int start, end; cin >> start >> end;
            edge[start].push_back(end);
        }

        cout << "#" << t << " ";
        bfs(M, edge, isVisited);
        cout << '\n';
    }
    return 0;
}

void bfs(int start, vector<vector<int>>& edge, vector<bool>& isVisited) {
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    isVisited[start] = true;

    int maxLevel = 0;
    vector<int> ans;

    while (!q.empty()) {
        int curNode = q.front().first;
        int curLevel = q.front().second;
        if (curLevel > maxLevel) {
            maxLevel = curLevel;
            ans.clear();
        }
        ans.push_back(curNode);
        q.pop();

        for (auto& nextNode : edge[curNode]) {
            if (isVisited[nextNode]) continue;
            isVisited[nextNode] = true;
            q.push({ nextNode, curLevel + 1 });
        }
    }

    sort(ans.rbegin(), ans.rend());
    cout << ans[0];

    return;
}