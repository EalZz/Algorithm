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
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];
long long memo[10001];

void dfs(int node, int sum, vector<vector<pair<int, int>>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(T + 1, vector<int>(3, 0));
    vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    fill(memo, memo + 10001, 0);

    vector<vector<pair<int, int>>> v(T + 1);
    for (int i = 0; i < T - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    
    isVisited[1] = true;
    dfs(1, 0, v, isVisited);

    cnt = 0;
    isVisited.assign(T + 1, false);

    isVisited[cnt1] = true;
    dfs(cnt1, 0, v, isVisited);
    
    cout << cnt;

    return 0;
}

void dfs(int node, int sum, vector<vector<pair<int, int>>>& v, vector<bool>& isVisited) {
    if (cnt < sum) {
        cnt = sum;
        cnt1 = node;
    }

    for (int i = 0; i < v[node].size(); i++) {
        if (isVisited[v[node][i].first]) continue;
        isVisited[v[node][i].first] = true;

        dfs(v[node][i].first, sum + v[node][i].second, v, isVisited);
    }
    return;
}