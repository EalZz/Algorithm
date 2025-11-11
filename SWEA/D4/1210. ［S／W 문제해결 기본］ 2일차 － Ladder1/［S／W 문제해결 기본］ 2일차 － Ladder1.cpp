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
        
        int start;
        vector<vector<bool>> v(100, vector<bool>(100, false));
        for (int row = 99; row >= 0; row--) {
            for (int col = 0; col < 100; col++) {
                int tmp; cin >> tmp;
                if (tmp == 1) v[row][col] = true;
                if (tmp == 2) start = col;
            }
        }

        int row = 0, col = start;
        while (row != 99) {
            if (col > 0 && v[row][col - 1]) col--;
            else if (col < 99 && v[row][col + 1]) col++;
            else row++;
            v[row][col] = false;
        }

        cout << "#" << t << " ";
        cout << col;
        cout << '\n';
    }
    return 0;
}
