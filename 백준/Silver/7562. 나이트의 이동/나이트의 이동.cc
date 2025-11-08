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

int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        int I; cin >> I;

        vector<vector<bool>> isVisited(I, vector<bool>(I));
        int srow, scol; cin >> srow >> scol;
        int erow, ecol; cin >> erow >> ecol;

        if (srow == erow && scol == ecol) {
            cout << 0 << '\n';
            continue;
        }

        queue<pair<pair<int, int>, int>> q;
        q.push({ {srow, scol}, 0 });
        isVisited[srow][scol] = true;

        bool isAble = false;
        while (!q.empty()) {
            int crow = q.front().first.first;
            int ccol = q.front().first.second;
            int curLevel = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int nrow = crow + dy[i];
                int ncol = ccol + dx[i];
                int nextLevel = curLevel + 1;

                if (nrow == erow && ncol == ecol) {
                    cout << nextLevel << '\n';
                    isAble = true;
                    break;
                }

                if (nrow >= I || ncol >= I || nrow < 0 || ncol < 0) continue;
                if (isVisited[nrow][ncol]) continue;

                isVisited[nrow][ncol] = true;
                q.push({ {nrow, ncol}, nextLevel });
            }
            if (isAble) break;
        }
        if (!isAble) cout << 0 << '\n';
    }

    return 0;
}