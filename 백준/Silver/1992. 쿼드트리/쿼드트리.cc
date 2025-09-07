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

void press(vector<vector<int>>& v, int size, int row, int col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string tmp;
    for (int row = 0; row < T;row++) {
        cin >> tmp;
        for (int col = 0; col < T; col++) v[row][col] = tmp[col] - '0';
    }

    press(v, T, 0, 0);

    return 0;
}

void press(vector<vector<int>>& v, int size, int row, int col) {
    int standard = v[row][col];
    bool isSame = true;

    if (size == 1) {
        cout << standard;
        return;
    }

    for (int nrow = row; nrow < row + size; nrow++) {
        for (int ncol = col; ncol < col + size; ncol++) {
            if (v[nrow][ncol] != standard) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }


    if (isSame) {
        cout << standard;
        return;
    }

    int half = size / 2;

    cout << '(';
    press(v, half, row, col);
    press(v, half, row, col + half);
    press(v, half, row + half, col);
    press(v, half, row + half, col + half);
    cout << ')';

    return;
}