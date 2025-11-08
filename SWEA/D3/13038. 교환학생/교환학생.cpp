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
        vector<int> v(7);
        for (int i = 0; i < 7; i++) cin >> v[i];

        int ans = 1e9;
        for (int i = 0; i < 7; i++) {
            int tmp = 0, cnt = 0, idx = i;
            while (cnt != n) {
                if (tmp >= ans) break;
                if (v[idx] == 1) cnt++;
                tmp++; idx++;
                if (idx >= 7) idx = 0;
            }
            ans = tmp;
        }


        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}