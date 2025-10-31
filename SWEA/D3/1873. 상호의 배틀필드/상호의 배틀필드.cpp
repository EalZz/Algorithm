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

int main() {
    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int H, W; cin >> H >> W;

        vector<vector<char>> v(H, vector<char>(W));
        pair<int, int> dir;
        
        for (int row = 0; row < H; row++) {
            string tmp; cin >> tmp;
            for (int col = 0; col < W; col++) {
                v[row][col] = tmp[col];
                if (v[row][col] == 'v' || v[row][col] == '^' || v[row][col] == '>' || v[row][col] == '<')
                    dir = { row, col };
            }
        }
        
        int N; cin >> N;
        string cord; cin >> cord;
        for (int i = 0; i < cord.size(); i++) {
            int crow = dir.first;
            int ccol = dir.second;
            switch (cord[i]) {
            case 'U':
                v[crow][ccol] = '^';
                if (crow - 1 >= 0 && v[crow - 1][ccol] == '.') {
                    v[crow - 1][ccol] = '^';
                    v[crow][ccol] = '.';
                    dir = { crow - 1, ccol };
                }
                break;
            case 'D':
                v[crow][ccol] = 'v';
                if (crow + 1 < H && v[crow + 1][ccol] == '.') {
                    v[crow + 1][ccol] = 'v';
                    v[crow][ccol] = '.';
                    dir = { crow + 1, ccol };
                }
                break;
            case 'L':
                v[crow][ccol] = '<';
                if (ccol - 1 >= 0 && v[crow][ccol - 1] == '.') {
                    v[crow][ccol - 1] = '<';
                    v[crow][ccol] = '.';
                    dir = { crow, ccol - 1 };
                }
                break;
            case 'R':
                v[crow][ccol] = '>';
                if (ccol + 1 < W && v[crow][ccol + 1] == '.') {
                    v[crow][ccol + 1] = '>';
                    v[crow][ccol] = '.';
                    dir = { crow, ccol + 1 };
                }
                break;
            case 'S':
                int nrow = crow;
                int ncol = ccol;
                switch (v[crow][ccol]) {
                case '^':
                    while (1) {
                        nrow--;
                        if (nrow < 0 || v[nrow][ncol] == '#') break;
                        if (v[nrow][ncol] == '*') {
                            v[nrow][ncol] = '.';
                            break;
                        }
                    }
                    break;
                case 'v':
                    while (1) {
                        nrow++;
                        if (nrow >= H || v[nrow][ncol] == '#') break;
                        if (v[nrow][ncol] == '*') {
                            v[nrow][ncol] = '.';
                            break;
                        }
                    }
                    break;
                case '<':
                    while (1) {
                        ncol--;
                        if (ncol < 0 || v[nrow][ncol] == '#') break;
                        if (v[nrow][ncol] == '*') {
                            v[nrow][ncol] = '.';
                            break;
                        }
                    }
                    break;
                case '>':
                    while (1) {
                        ncol++;
                        if (ncol >= W || v[nrow][ncol] == '#') break;
                        if (v[nrow][ncol] == '*') {
                            v[nrow][ncol] = '.';
                            break;
                        }
                    }
                    break;
                }
                break;
            }
        }

        cout << "#" << t << ' ';
        for (int row = 0; row < H; row++) {
            for (int col = 0; col < W; col++) cout << v[row][col];
            cout << '\n';
        }
    }
    return 0;
}
