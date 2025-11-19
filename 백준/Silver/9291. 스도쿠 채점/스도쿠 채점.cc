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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        bool isAble = true;
        vector<vector<int>> v(9, vector<int>(9));
        for (int row = 0; row < 9; row++) {
            vector<bool> isVisited(10, false);
            for (int col = 0; col < 9; col++) {
                cin >> v[row][col];
                if (isVisited[v[row][col]]) isAble = false;
                isVisited[v[row][col]] = true;
            }
        }

        for (int col = 0; col < 9; col++) {
            vector<bool> isVisited(10, false);
            for (int row = 0; row < 9; row++) {
                if (isVisited[v[row][col]]) {
                    isAble = false;
                    break;
                }
                isVisited[v[row][col]] = true;
            }
            if (!isAble) break;
        }

        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                vector<bool> isVisited(10, false);
                for (int i = row; i < row + 3; i++) {
                    for (int j = col; j < col + 3; j++) {
                        if (isVisited[v[i][j]]) {
                            isAble = false;
                            break;
                        }
                        isVisited[v[i][j]] = true;
                    }
                    if (!isAble) break;
                }
                if (!isAble) break;
            }
            if (!isAble) break;
        }

        cout << "Case " << t << ": ";
        if (isAble) cout << "CORRECT";
        else cout << "INCORRECT";
        cout << '\n';
    }



    return 0;
}