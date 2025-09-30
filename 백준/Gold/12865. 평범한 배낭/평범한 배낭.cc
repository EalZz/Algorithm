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
long long memo[101][100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    vector<vector<int>> v(T + 1, vector<int>(3, 0));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 1; row <= T; row++) {
        for (int col = 1; col <= 2; col++) cin >> v[row][col];
    }


    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= N; j++) {
            int curW = v[i][1];
            int curV = v[i][2];

            if (j < curW) memo[i][j] = memo[i - 1][j];
            else memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - curW] + curV);
        }
    }

    cout << memo[T][N];

    return 0;
}