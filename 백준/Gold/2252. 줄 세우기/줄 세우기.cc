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

void Topology(vector<vector<int>>& v, vector<int>& indegree);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<long long> v(T + 1, 0);
    vector<vector<int>> v(T + 1);
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<int> indegree(T + 1, 0);
    for (int i = 0; i < N; i++) {
        int start, end; cin >> start >> end;
        v[start].push_back(end);
        indegree[end]++;
    }

    fill(memo, memo + T + 1, 0);
    Topology(v, indegree);

    for (int i = 1; i <= T; i++) cout << memo[i] << ' ';

    return 0;
}

void Topology(vector<vector<int>>& v, vector<int>& indegree) {
    queue<int> q;
    for (int i = 1; i < v.size(); i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    int idx = 1;
    while (!q.empty()) {
        int cur = q.front();
        memo[idx] = cur;
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            indegree[next]--;
            if (indegree[next] == 0) q.push(next);
        }
        idx++;
    }
}