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

void bfs(int R, vector<vector<int>>& edge, vector<int>& order, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, R; cin >> N >> M >> R;

    vector<vector<int>> edge(N + 1);
    vector<bool> isVisited(N + 1, false);
    vector<int> order(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (auto& v : edge) sort(v.begin(), v.end());

    bfs(R, edge, order, isVisited);
    
    for (int i = 1; i <= N; i++) cout << order[i] << '\n';

    return 0;
}

void bfs(int R, vector<vector<int>>& edge, vector<int>& order, vector<bool>& isVisited) {
    queue<int> q;
    q.push(R);
    isVisited[R] = true;

    int cnt = 1;
    order[R] = cnt;
    cnt++;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        for (int i = 0; i < edge[curNode].size(); i++) {
            int nextNode = edge[curNode][i];

            if (isVisited[nextNode]) continue;

            q.push(nextNode);
            isVisited[nextNode] = true;

            order[nextNode] = cnt;
            cnt++;
        }
    }

    return;
}