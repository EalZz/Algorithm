#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<vector<char>> v(N, vector<char>(N));

    for (int row = 0; row < N; row++) {
        string s;
        cin >> s;
        for (int col = 0; col < N; col++) {
            v[row][col] = s[col];
        }
    }

    int ans_row = 0;
    int cnt = 0;

    for (int row = 0; row < N; row++) {
        cnt = 0;
        for (int col = 0; col < N; col++) {
            if (v[row][col] == '.') {
                cnt++;
            }
            else {
                if (cnt >= 2) ans_row++;
                cnt = 0;
            }
        }
        if (cnt >= 2) ans_row++;
    }

    int ans_col = 0;

    for (int col = 0; col < N; col++) {
        cnt = 0;
        for (int row = 0; row < N; row++) {
            if (v[row][col] == '.') {
                cnt++;
            }
            else {
                if (cnt >= 2) ans_col++;
                cnt = 0;
            }
        }
        if (cnt >= 2) ans_col++;
    }

    cout << ans_row << ' ' << ans_col;

    return 0;
}
