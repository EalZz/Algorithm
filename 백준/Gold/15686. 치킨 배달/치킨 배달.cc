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
int cnt = 1e9, cnt1 = 0;
int memo[21][21][21];
//int memo[10000001];
void ckdistance(int idx, int N, vector<vector<int>>& home, vector<vector<int>>& ckhouse, vector<vector<int>>& select);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<vector<int>> home;
    vector<vector<int>> ckhouse;
    vector<vector<int>> select;

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) {
            cin >> v[row][col];
            if (v[row][col] == 1) home.push_back({ row, col });
            if (v[row][col] == 2) ckhouse.push_back({ row, col });
        }
    }
    ckdistance(0, N, home, ckhouse, select);
    cout << cnt;

    return 0;
}

void ckdistance(int idx, int N, vector<vector<int>>& home, vector<vector<int>>& ckhouse, vector<vector<int>>& select) {
    if (select.size() == N) {
        int sum = 0;
        for (auto h : home) {
            int dist = 1e9;
            for (auto s : select) dist = min(dist, abs(h[0] - s[0]) + abs(h[1] - s[1]));
            sum += dist;
        }
        cnt = min(cnt, sum);
        return;
    }

    if (idx == ckhouse.size()) return;

    select.push_back(ckhouse[idx]);
    ckdistance(idx + 1, N, home, ckhouse, select);
    select.pop_back();

    ckdistance(idx + 1, N, home, ckhouse, select);

    return;
}