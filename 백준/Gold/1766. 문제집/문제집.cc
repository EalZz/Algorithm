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

using namespace std;
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

void Topology(vector<vector<int>>& edge, vector<int>& indegree);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> edge(N + 1);
    vector<int>indegree(N + 1, 0);
    while (M--) {
        int s, e; cin >> s >> e;
        edge[s].push_back(e);
        indegree[e]++;
    }

    Topology(edge, indegree);

    return 0;
}

void Topology(vector<vector<int>>& edge, vector<int>& indegree) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 0) pq.push(i);
    }

    while (!pq.empty()) {
        int curNode = pq.top();
        pq.pop();
        cout << curNode << ' ';

        for (int i = 0; i < edge[curNode].size(); i++) {
            int nextNode = edge[curNode][i];
            indegree[nextNode]--;
            if (indegree[nextNode] == 0) pq.push(nextNode);
        }
    }
    return;
}
