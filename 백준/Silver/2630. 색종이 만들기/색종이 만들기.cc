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
//int memo[21][21][21];
int memo[10000001];

void comp(int T, int row, int col, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0;

    vector<vector<int>> v(T, vector<int>(T));
    string line;

    for (int row = 0; row < T; row++) {
        //cin >> line;
        for (int col = 0; col < T; col++) {
            //v[row][col] = line[col] - '0';
            cin >> v[row][col];
        }
    }

    comp(T, 0, 0, v);
    cout << cnt << '\n'
        << cnt1;

    return 0;
}

void comp(int T, int row, int col, vector<vector<int>>& v) {
    bool isSame = true;
    int standard = v[row][col];
    for (int crow = row; crow < row + T; crow++) {
        for (int ccol = col; ccol < col + T; ccol++) {
            if (v[crow][ccol] != standard) {
                isSame = false;
                break;
            }
        }
        if (!isSame) break;
    }

    if (isSame) {
        if (standard == 0) cnt++;
        else cnt1++;
        return;
    }
    else {
        int token = T / 2;
        comp(token, row, col, v);
        comp(token, row, col + token, v);
        comp(token, row + token, col, v);
        comp(token, row + token, col + token, v);
    }

    return;
}