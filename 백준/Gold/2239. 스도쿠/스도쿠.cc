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
#include <list>

using namespace std;

bool dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& vrow, vector<vector<bool>>& vcol, vector<vector<bool>>& vbox);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> v(9, vector<int>(9, 0));
    vector<vector<bool>> vrow(9, vector<bool>(10, false));
    vector<vector<bool>> vcol(9, vector<bool>(10, false));
    vector<vector<bool>> vbox(9, vector<bool>(10, false));

    for (int row = 0; row < 9; row++) {
        string tmp; cin >> tmp;
        for (int col = 0; col < 9; col++) {
            v[row][col] = tmp[col] - '0';
            if (v[row][col] != 0) {
                int box = (row / 3) * 3 + (col / 3);
                vrow[row][v[row][col]] = true;
                vcol[col][v[row][col]] = true;
                vbox[box][v[row][col]] = true;
            }
        }
    }

    dfs(0, 0, v, vrow, vcol, vbox);

    return 0;
}

bool dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& vrow, vector<vector<bool>>& vcol, vector<vector<bool>>& vbox) {
    if (row == 9) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << v[i][j];
            cout << '\n';
        }
        return true;
    }

    int nextRow = (col == 8) ? row + 1 : row;
    int nextCol = (col == 8) ? 0 : col + 1;
    if (v[row][col] != 0) return dfs(nextRow, nextCol, v, vrow, vcol, vbox);

    int box = (row / 3) * 3 + (col / 3);

    for (int i = 1; i <= 9; i++) {
        if (vrow[row][i] || vcol[col][i] || vbox[box][i]) continue;

        vrow[row][i] = true;
        vcol[col][i] = true;
        vbox[box][i] = true;
        v[row][col] = i;

        if (dfs(nextRow, nextCol, v, vrow, vcol, vbox)) return true;

        vrow[row][i] = false;
        vcol[col][i] = false;
        vbox[box][i] = false;
        v[row][col] = 0;
    }
    return false;
}