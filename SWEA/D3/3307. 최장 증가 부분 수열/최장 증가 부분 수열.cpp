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
        vector<int> v(N), lis;
        for (int i = 0; i < N; i++) cin >> v[i];
        lis.push_back(v[0]);

        for (int i = 1; i < N; i++) {
            int cur = v[i];
            int pos = lower_bound(lis.begin(), lis.end(), cur) - lis.begin();

            if (pos == lis.size()) lis.push_back(cur);
            else lis[pos] = cur;
        }

        cout << "#" << t << " ";
        cout << lis.size();
        cout << '\n';
    }
    return 0;
}