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
long long memo[50001];
//int memo[101][4];

void dfs(int row, int node, vector<vector<int>>& v, vector<bool>& isVisited, vector<vector<int>>& newv);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T, 0);
    vector<vector<int>> v(T);
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) {
            int tmp; cin >> tmp;
            if (tmp == 1) v[row].push_back(col);
        }
    }

    vector<vector<int>> newv(T, vector<int>(T, 0));
    for (int i = 0; i < T; i++) {
        vector<bool> isVisited(T, false);
        dfs(i, i, v, isVisited, newv);
    }

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) cout << newv[row][col] << ' ';
        cout << '\n';
    }

    return 0;
}

void dfs(int row, int node, vector<vector<int>>& v, vector<bool>& isVisited, vector<vector<int>>& newv) {
    for (auto& next : v[node]) {
        if (!isVisited[next]) {
            isVisited[next] = true;
            newv[row][next] = 1;
            dfs(row, next, v, isVisited, newv);
        }
    }
    return;
}
