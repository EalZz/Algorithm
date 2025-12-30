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

int bfs(vector<vector<int>>& edge, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> edge(N + 1);
    vector<bool> isVisited(N + 1, false);

    while (M--) {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    cout << bfs(edge, isVisited);

    return 0;
}

int bfs(vector<vector<int>>& edge, vector<bool>& isVisited) {
    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    isVisited[1] = true;

    int cnt = 0;
    while (!q.empty()) {
        int curNode = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        if (curLevel >= 2) break;

        for (auto& nextNode : edge[curNode]) {
            if (isVisited[nextNode]) continue;

            cnt++;
            q.push({ nextNode, curLevel + 1 });
            isVisited[nextNode] = true;
        }
    }

    return cnt;
}