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
//int memo[21][21][21];
//int memo[10000001];

void quadtree(int T, int row, int col, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string tmp;
    for (int row = 0; row < T; row++) {
        cin >> tmp;
        for (int col = 0; col < T; col++) v[row][col] = tmp[col] - '0';
    }

    quadtree(T, 0, 0, v);

    return 0;
}

void quadtree(int T, int row, int col, vector<vector<int>>& v) {
    int standard = v[row][col];
    bool isSame = true;

    for (int i = row; i < row + T; i++) {
        for (int j = col; j < col + T; j++) {
            if (v[i][j] != standard) {
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

    int token = T / 2;

    cout << '(';
    quadtree(token, row, col, v);
    quadtree(token, row, col + token, v);
    quadtree(token, row + token, col, v);
    quadtree(token, row + token, col + token, v);
    cout << ')';

    return;
}