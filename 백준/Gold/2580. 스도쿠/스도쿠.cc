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

bool sudoku(int row, int col, vector<vector<bool>>& brow, vector<vector<bool>>& bcol, vector<vector<bool>>& bbox, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 9; //cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<vector<bool>> brow(9, vector<bool>(10, false));
    vector<vector<bool>> bcol(9, vector<bool>(10, false));
    vector<vector<bool>> bbox(9, vector<bool>(10, false));

    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            int num = 0; cin >> num;
            v[row][col] = num;
            if (num != 0) {
                int box = (row / 3) * 3 + (col / 3);
                brow[row][num] = true;
                bcol[col][num] = true;
                bbox[box][num] = true;
            }
        }
    }

    sudoku(0, 0, brow, bcol, bbox, v);

    return 0;
}

bool sudoku(int row, int col, vector<vector<bool>>& brow, vector<vector<bool>>& bcol, vector<vector<bool>>& bbox, vector<vector<int>>& v) {
    if (row == 9) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) cout << v[row][col] << ' ';
            cout << '\n';
        }
        return true;
    }

    int nrow = (col == 8) ? row + 1 : row;
    int ncol = (col == 8) ? 0 : col + 1;

    if (v[row][col] != 0) return sudoku(nrow, ncol, brow, bcol, bbox, v);

    int box = (row / 3) * 3 + (col / 3);

    for (int num = 1; num <= 9;num++) {
        if (!brow[row][num] && !bcol[col][num] && !bbox[box][num]) {
            brow[row][num] = true;
            bcol[col][num] = true;
            bbox[box][num] = true;
            v[row][col] = num;

            if(sudoku(nrow, ncol, brow, bcol, bbox, v)) return true;

            brow[row][num] = false;
            bcol[col][num] = false;
            bbox[box][num] = false;
            v[row][col] = 0;
        }
    }
    return false;
}