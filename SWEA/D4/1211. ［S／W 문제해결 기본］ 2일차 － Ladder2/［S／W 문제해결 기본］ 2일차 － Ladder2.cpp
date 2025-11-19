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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        int tc; cin >> tc;

        vector<vector<bool>> v(100, vector<bool>(100, true));
        for (int row = 0; row < 100; row++) {
            for (int col = 0; col < 100; col++) {
                int tmp; cin >> tmp;
                if (tmp == 1) v[row][col] = false;
            }
        }

        int minLen = 1e9, ans = -1;
        for (int start = 0; start < 100; start++) {
            if (v[0][start]) continue;

            vector<vector<bool>> isVisited = v;
            int row = 0, col = start, len = 0;
            while (1) {
                isVisited[row][col] = true;

                if (col - 1 >= 0 && !isVisited[row][col - 1]) col--;
                else if (col + 1 < 100 && !isVisited[row][col + 1]) col++;
                else row++;

                if (row == 100) break;

                len++;
            }

            if (len <= minLen) {
                minLen = len;
                ans = start;
            }
        }

        cout << "#" << tc << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}
