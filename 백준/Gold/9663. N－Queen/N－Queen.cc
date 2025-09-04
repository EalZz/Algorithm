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

void n_queen(int T, int row, int col, vector<bool>& colA, vector<bool>& diag1, vector<bool>& diag2);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<bool> colA(T, false);
    vector<bool> diag1(2 * T - 1, false);
    vector<bool> diag2(2 * T - 1, false);


    for (int col = 0; col < T; col++) {
        n_queen(T, 0, col, colA, diag1, diag2);
    }
    cout << cnt;

    return 0;
}

void n_queen(int T, int row, int col, vector<bool>& colA, vector<bool>& diag1, vector<bool>& diag2) {
    if (row == T - 1) {
        cnt++;
        return;
    }

    colA[col] = true;
    diag1[(row - col) + (T - 1)] = true;
    diag2[row + col] = true;

    for (int i = 0; i < T; i++) {
        if (!colA[i] && !diag1[(row + 1 - i) + (T - 1)] && !diag2[row + 1 + i])
            n_queen(T, row + 1, i, colA, diag1, diag2);
    }

    colA[col] = false;
    diag1[(row - col) + (T - 1)] = false;
    diag2[row + col] = false;

    return;
}