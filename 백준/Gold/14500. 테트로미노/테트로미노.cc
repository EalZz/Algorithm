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
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(101, 0);
    vector<vector<int>> v(T, vector<int>(N, 0));
    //vector<bool> isVisited(10001, false);
    vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T;row++) {
        for (int col = 0; col < N;col++) cin >> v[row][col];
    }

    int maxSum = 0;
    for (int row = 0; row < T;row++) {
        for (int col = 0; col < N;col++) {
            isVisited[row][col] = true;
            maxSum = max(maxSum, dfs(v[row][col], 1, row, col, v, isVisited));
            isVisited[row][col] = false;
        }
    }

    for (int row = 0; row < T;row++) {
        for (int col = 0; col < N;col++) {
            int sum = 0;
            if ((row == 0 && col == 0) || (row == T - 1 && col == 0) || (row == 0 && col == N - 1) || (row == T - 1 && col == N - 1)) continue;
            if (row == 0) sum = v[row][col] + v[row][col - 1] + v[row][col + 1] + v[row + 1][col];
            else if (row == T - 1)sum = v[row][col] + v[row][col - 1] + v[row][col + 1] + v[row - 1][col];
            else if (col == 0) sum = v[row][col] + v[row - 1][col] + v[row + 1][col] + v[row][col + 1];
            else if (col == N - 1) sum = v[row][col] + v[row - 1][col] + v[row + 1][col] + v[row][col - 1];
            else {
                int minv[4];
                minv[0] = v[row][col - 1];
                minv[1] = v[row][col + 1];
                minv[2] = v[row - 1][col];
                minv[3] = v[row + 1][col];
                sort(minv, minv + 4);

                sum = v[row][col] + minv[1] + minv[2] + minv[3];
            }

            maxSum = max(maxSum, sum);
        }
    }

    cout << maxSum;

    return 0;
}

int dfs(int sum, int cnt, int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited) {
    int dy[4] = { 0, 0, 1, -1 };
    int dx[4] = { 1, -1, 0, 0 };

    if (cnt == 4) return sum;

    int msum = -1e9;
    for (int i = 0; i < 4; i++) {
        int ny = row + dy[i];
        int nx = col + dx[i];

        if (ny < 0 || nx < 0 || ny >= v.size() || nx >= v[0].size()) continue;
        if (isVisited[ny][nx]) continue;

        isVisited[ny][nx] = true;
        sum += v[ny][nx];

        msum = max(msum, dfs(sum, cnt + 1, ny, nx, v, isVisited));

        isVisited[ny][nx] = false;
        sum -= v[ny][nx];
    }
    return msum;
}