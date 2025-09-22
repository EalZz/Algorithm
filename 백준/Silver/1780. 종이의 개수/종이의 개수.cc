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
//int cnt = 0, cnt1 = 1e9;
int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[101];
int memo[101][4];

void dfs(int size, int row, int col, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    vector<vector<int>> v(T, vector<int>(T, 0));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) cin >> v[row][col];
    }

    dfs(T, 0, 0, v);

    cout << cnt_1 << '\n'
        << cnt0 << '\n'
        << cnt1;

    return 0;
}

void dfs(int size, int row, int col, vector<vector<int>>& v) {
    int standard = v[row][col];
    bool isSame = true;
    for (int i = row; i < row + size; i++) {
        for (int j = col; j < col + size; j++) {
            if (v[i][j] != standard) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        switch (standard) {
        case -1: 
            cnt_1++;
            break;
        case 0:
            cnt0++;
            break;
        case 1:
            cnt1++;
            break;
        }
    }
    else {
        int token = size / 3;
        for (int i = 0; i < size; i += size / 3) {
            for (int j = 0; j < size; j += size / 3)
                dfs(size / 3, row + i, col + j, v);
        }
    }
}