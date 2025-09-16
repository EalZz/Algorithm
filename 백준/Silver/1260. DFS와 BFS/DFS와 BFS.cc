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
//int cnt = 0, cnt1 = 1e9;
//int memo[21][21][21];
//int memo[10000001];

void dfs(int node, vector<vector<int>>& v, vector<bool>& isVisited);
void bfs(int node, queue<int>& q, vector<vector<int>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<int> tmp;
    vector<vector<int>> v(a + 1);
    vector<bool> isVisited(a + 1, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    queue<int> q;

    for (int i = 0; i < b; i++) {
        int tmp1 = 0, tmp2 = 0;
        cin >> tmp1 >> tmp2;

        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }
    for (int i = 1; i <= a; i++) sort(v[i].begin(), v[i].end());

    isVisited[c] = true;
    dfs(c, v, isVisited);

    cout << '\n';
    for (int i = 0; i < isVisited.size(); i++) isVisited[i] = false;

    isVisited[c] = true;
    q.push(c);
    bfs(c, q, v, isVisited);

    return 0;
}

void dfs(int node, vector<vector<int>>& v, vector<bool>& isVisited) {
    cout << node << ' ';

    for (int i = 0; i < v[node].size(); i++) {
        if (!isVisited[v[node][i]]) {
            isVisited[v[node][i]] = true;
            dfs(v[node][i], v, isVisited);
        }
    }
    return;
}

void bfs(int node, queue<int>& q, vector<vector<int>>& v, vector<bool>& isVisited) {
    while (!q.empty()) {
        int usingNum = q.front();
        q.pop();

        cout << usingNum << ' ';

        for (int i = 0; i < v[usingNum].size(); i++) {
            if (!isVisited[v[usingNum][i]]) {
                isVisited[v[usingNum][i]] = true;
                q.push(v[usingNum][i]);
            }
        }
    }
    return;
}