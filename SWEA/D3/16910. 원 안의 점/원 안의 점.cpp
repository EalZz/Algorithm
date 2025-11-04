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

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int n; cin >> n;
        int ans = n * 4 + 1;

        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i * i + j * j > n * n) break;
                tmp++;
            }
        }

        cout << "#" << t << " ";
        cout << ans + tmp * 4;
        cout << '\n';
    }
    return 0;
}