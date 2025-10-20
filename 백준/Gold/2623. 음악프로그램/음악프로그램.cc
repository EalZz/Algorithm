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
long long memo[10001];
long long preNode[1001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

vector<int> Topology(vector<vector<int>>& edge, vector<int>& indegree);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> edge(N + 1);
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int c; cin >> c;
        int pre; cin >> pre;
        for (int j = 1; j < c; j++) {
            int cur; cin >> cur;
            edge[pre].push_back(cur);
            indegree[cur]++;
            pre = cur;
        }
    }

    vector<int> result = Topology(edge, indegree);
    if (result.size() != N) cout << 0;
    else {
        for (auto& i : result) cout << i << '\n';
    }

    return 0;
}

vector<int> Topology(vector<vector<int>>& edge, vector<int>& indegree) {
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> result;
    while (!q.empty()) {
        int curNode = q.front();
        q.pop();
        result.push_back(curNode);

        for (int i = 0; i < edge[curNode].size(); i++) {
            int nextNode = edge[curNode][i];
            indegree[nextNode]--;
            if (indegree[nextNode] == 0) q.push(nextNode);
        }
    }
    return result;
}
