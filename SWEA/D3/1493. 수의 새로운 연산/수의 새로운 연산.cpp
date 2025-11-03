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

    int T = 10; cin >> T;

    map<int, pair<int, int>> m;
    map<pair<int, int>, int> rm;

    int x = 1, y = 1, sum = 2;
    for (int i = 1; i <= 50000; i++) {
        m[i] = { x, y };
        rm[{x, y}] = i;
        if (y == 1) {
            sum++;
            x = 1;
            y = sum - 1;
        }
        else {
            x++;
            y--;
        }
    }

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int p, q; cin >> p >> q;

        cout << "#" << t << " ";
        cout << rm[{ m[p].first + m[q].first, m[p].second + m[q].second }];
        cout << '\n';
    }
    return 0;
}