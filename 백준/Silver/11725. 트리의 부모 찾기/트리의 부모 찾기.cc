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
//long long memo[1001];
//int memo[101][4];

int dfs(int sum, int cnt, int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    vector<vector<int>> v(T + 1);
    vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T - 1; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    vector<int> p(T + 1);
    queue<int> q;
    q.push(1);
    isVisited[1] = true;

    while (!q.empty()) {
        int curNode = q.front();
        q.pop();

        for (auto& n : v[curNode]) {
            if (isVisited[n]) continue;
            isVisited[n] = true;
            p[n] = curNode;

            q.push(n);
        }
    }

    for (int i = 2; i <= T; i++) cout << p[i] << '\n';

    return 0;
}