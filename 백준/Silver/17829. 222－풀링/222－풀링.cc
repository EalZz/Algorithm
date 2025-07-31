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

using namespace std;

int cnt = 0;
int qmatrix(vector<vector<int>>& matrix, int row, int col, int T);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N = 0, K = 0; 
    //cin >> N >> K;
    int T = 0; cin >> T;

    vector<vector<int>> matrix(T, vector<int>(T));

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) cin >> matrix[i][j];
    }

    cout << qmatrix(matrix, 0, 0, T);

    return 0;
}

int qmatrix(vector<vector<int>>& matrix, int row, int col, int T) {
    int tmp[4];

    if (T == 2) {
        tmp[0] = matrix[row][col];
        tmp[1] = matrix[row][col + 1];
        tmp[2] = matrix[row + 1][col];
        tmp[3] = matrix[row + 1][col + 1];

        sort(tmp, tmp + 4);
        return tmp[2];
    }

    tmp[0] = qmatrix(matrix, row, col, T / 2);
    tmp[1] = qmatrix(matrix, row, col + T / 2, T / 2);
    tmp[2] = qmatrix(matrix, row + T / 2, col, T / 2);
    tmp[3] = qmatrix(matrix, row + T / 2, col + T / 2, T / 2);

    sort(tmp, tmp + 4);
    return tmp[2];
}