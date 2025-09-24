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
//long long memo[101];
int memo[101][4];

void dfs(int node, vector<vector<int>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    vector<vector<int>> v(T + 1);
    vector<bool> isVisited(T + 1, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    isVisited[1] = true;
    dfs(1, v, isVisited);

    cout << cnt;

    return 0;
}

void dfs(int node, vector<vector<int>>& v, vector<bool>& isVisited) {
    for (int i = 0; i < v[node].size(); i++) {
        if (!isVisited[v[node][i]]) {
            isVisited[v[node][i]] = true;
            cnt++;
            dfs(v[node][i], v, isVisited);
        }
    }
    return;
}