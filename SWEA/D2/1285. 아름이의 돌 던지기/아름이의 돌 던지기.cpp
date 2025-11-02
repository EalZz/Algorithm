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

        int N; cin >> N;
        int ans = 0, minv = 1e9;
        while (N--) {
            int ts; cin >> ts;
            int tmp = abs(ts);
            if (tmp < minv) {
                minv = tmp;
                ans = 1;
            }
            else if (tmp == minv) ans++;
        }

        cout << '#' << t << ' ';
        cout << minv << ' ' << ans;
        cout << '\n';
    }
    return 0;
}
