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
long long memo[100001];
//int memo[101][4];

int dfs(int row, int col, vector<vector<int>>& v, vector<bool>& isAlpha);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1);
    vector<vector<int>> v(T, vector<int>(N));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < N; col++) {
            char tmp; cin >> tmp;
            v[row][col] = tmp - 'A';
        }
    }

    vector<bool> isAlpha(26);
    isAlpha[v[0][0]] = true;

    cout << dfs(0, 0, v, isAlpha);

    return 0;
}

int dfs(int row,int col, vector<vector<int>>& v, vector<bool>& isAlpha) {
    int dy[4] = {1, -1 ,0 , 0};
    int dx[4] = { 0, 0, 1, -1 };

    int maxCount = 1;

    for (int i = 0; i < 4; i++) {
        int ny = row + dy[i];
        int nx = col + dx[i];

        if (ny < 0 || nx < 0 || ny >= v.size() || nx >= v[0].size()) continue;
        if (isAlpha[v[ny][nx]]) continue;

        isAlpha[v[ny][nx]] = true;
        int count = dfs(ny, nx, v, isAlpha);
        maxCount = max(maxCount, count + 1);
        isAlpha[v[ny][nx]] = false;
    }

    return maxCount;
} 