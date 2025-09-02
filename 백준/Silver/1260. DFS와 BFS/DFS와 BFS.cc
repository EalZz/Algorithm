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
int cnt = 0, cnt1 = 0;
int memo[21][21][21];
//int memo[10000001];

void dfs(int c, vector<vector<int>>& edge, vector<bool>& isVisited);
void bfs(int c, vector<vector<int>>& edge, queue<int>& q, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> edge (a + 1);
    vector<bool> isVisited(a + 1, false);
    queue<int> q;
    //vector<vector<int>> matrix(b, vector<int>(2));
    for (int i = 0; i < b; i++) {
        int tmp1 = 0; cin >> tmp1;
        int tmp2 = 0; cin >> tmp2;
        edge[tmp1].push_back(tmp2);
        edge[tmp2].push_back(tmp1);
    }
    for (int i = 1; i <= a; i++) sort(edge[i].begin(), edge[i].end());

    isVisited[c] = true;
    dfs(c, edge, isVisited);

    for (int i = 0; i < isVisited.size(); i++) isVisited[i] = false;
    cout << '\n';

    isVisited[c] = true;
    bfs(c, edge, q, isVisited);

    return 0;
}

void dfs(int c, vector<vector<int>>& edge, vector<bool>& isVisited) {
    cout << c << ' ';
    for (int i = 0; i < edge[c].size(); i++) {
        if (!isVisited[edge[c][i]]) {
            isVisited[edge[c][i]] = true;
            dfs(edge[c][i], edge, isVisited);
        }
    }
    return;
}

void bfs(int c, vector<vector<int>>& edge, queue<int>& q, vector<bool>& isVisited) {
    q.push(c);
    while (!q.empty()) {
        int usingNode = q.front();
        cout << usingNode << ' ';
        q.pop();

        for (int i = 0; i < edge[usingNode].size(); i++) {
            if (!isVisited[edge[usingNode][i]]) {
                isVisited[edge[usingNode][i]] = true;
                q.push(edge[usingNode][i]);
            }
        }
    }
    return;
}