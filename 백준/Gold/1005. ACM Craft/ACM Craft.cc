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
//long long memo[3];
//long long memo[101][10];
long long memo[100001];
//long long MOD = 1000000000;

void Topology(vector<int>& vcost, vector<int>& indegree, vector<vector<int>>& gr);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        int N, K; cin >> N >> K;
        vector<int> vcost(N + 1);
        vector<int> indegree(N + 1);
        vector<vector<int>> gr(N + 1);
        
        fill(memo, memo + N + 1, 0);

        for (int i = 1; i <= N; i++) cin >> vcost[i];
        for (int i = 0; i < K; i++) {
            int start, end; cin >> start >> end;
            gr[start].push_back(end);
            indegree[end]++;
        }
        Topology(vcost, indegree, gr);

        int target; cin >> target;
        cout << memo[target] << '\n';
    }

    return 0;
}

void Topology(vector<int>& vcost, vector<int>& indegree, vector<vector<int>>& gr) {
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
            memo[i] = vcost[i];
        }
    }

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        for (int i = 0; i < gr[curNode].size(); i++) {
            int nextNode = gr[curNode][i];

            memo[nextNode] = max(memo[nextNode], memo[curNode] + vcost[nextNode]);
            indegree[nextNode]--;
            if (indegree[nextNode] == 0) q.push(nextNode);
        }
    }
}