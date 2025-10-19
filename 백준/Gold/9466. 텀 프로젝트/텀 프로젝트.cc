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

void dfs(int node, vector<vector<int>>& v, vector<bool>& isVisited, vector<bool>& isTeam);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        cnt = 0;
        int N; cin >> N;
        vector<vector<int>> v(N + 1);
        vector<bool> isVisited(N + 1, false), isTeam(N + 1, false);
        for (int i = 1; i <= N; i++) {
            int tmp; cin >> tmp;
            v[i].push_back(tmp);
        }

        for (int i = 1; i <= N; i++) {
            if (isVisited[i]) continue;
            isVisited[i] = true;
            dfs(i, v, isVisited, isTeam);
        }

        cout << N - cnt << '\n';
    }

    return 0;
}

void dfs(int node, vector<vector<int>>& v, vector<bool>& isVisited, vector<bool>& isTeam) {
    int nextNode = v[node][0];

    if (!isVisited[nextNode]) {
        isVisited[nextNode] = true;
        dfs(nextNode, v, isVisited, isTeam);
    }
    else if (!isTeam[nextNode]) {
        int cur = nextNode;
        while (1) {
            cnt++;
            if (cur == node) break;
            cur = v[cur][0];
        }
    }
    isTeam[node] = true;

    return;
}