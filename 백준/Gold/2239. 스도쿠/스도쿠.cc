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
//long long memo[3];
//long long memo[101][10];
//long long memo[100001];
//long long MOD = 1000000000;

bool dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& brow, vector<vector<bool>>& bcol, vector<vector<bool>>& bbox);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<vector<int>> v(9, vector<int>(9, 0));
    vector<vector<bool>> brow(9, vector<bool>(10, false));
    vector<vector<bool>> bcol(9, vector<bool>(10, false));
    vector<vector<bool>> bbox(9, vector<bool>(10, false));

    string tmp;
    for (int row = 0; row < 9; row++) {
        cin >> tmp;
        for (int col = 0; col < 9; col++) {
            int num = tmp[col] - '0';
            v[row][col] = num;
            if (num != 0) {
                int box = (row / 3) * 3 + (col / 3);
                brow[row][num] = true;
                bcol[col][num] = true;
                bbox[box][num] = true;
            }
        }
    }

    dfs(0, 0, v, brow, bcol, bbox);

    return 0;
}

bool dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& brow, vector<vector<bool>>& bcol, vector<vector<bool>>& bbox) {
    if (row == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << v[i][j];
            cout << '\n';
        }
        return true;
    }

    int nrow = (col == 8) ? row + 1 : row;
    int ncol = (col == 8) ? 0 : col + 1;

    if (v[row][col] != 0) return dfs(nrow, ncol, v, brow, bcol, bbox);

    int box = (row / 3) * 3 + (col / 3);

    for (int num = 1; num <= 9; num++) {
        if (brow[row][num] || bcol[col][num] || bbox[box][num]) continue;

        brow[row][num] = true;
        bcol[col][num] = true;
        bbox[box][num] = true;
        v[row][col] = num;

        if (dfs(nrow, ncol, v, brow, bcol, bbox)) return true;

        brow[row][num] = false;
        bcol[col][num] = false;
        bbox[box][num] = false;
        v[row][col] = 0;
    }
    return false;
}