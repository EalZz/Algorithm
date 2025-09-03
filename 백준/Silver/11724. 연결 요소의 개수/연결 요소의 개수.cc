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
void dfs(int i, vector<vector<int>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> v(T + 1);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    vector<bool> isVisited(T + 1, false);

    for (int i = 0; i < N; i++) {
        int tmp1 = 0; cin >> tmp1;
        int tmp2 = 0; cin >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    for (int i = 1; i <= T; i++) {
        if (!isVisited[i]) {
            cnt++;
            dfs(i, v, isVisited);
        }
    }

    cout << cnt;

    return 0;
}

void dfs(int i, vector<vector<int>>& v, vector<bool>& isVisited) {
    for (int j = 0; j < v[i].size(); j++) {
        if (!isVisited[v[i][j]]) {
            isVisited[v[i][j]] = true;
            dfs(v[i][j], v, isVisited);
        }
    }
    return;
}