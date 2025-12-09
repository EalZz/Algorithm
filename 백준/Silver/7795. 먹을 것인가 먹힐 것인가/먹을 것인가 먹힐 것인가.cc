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
    
    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        vector<int> v1(a), v2(b);
        for (int i = 0; i < a; i++) cin >> v1[i];
        for (int i = 0; i < b; i++) cin >> v2[i];
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        int cnt = 0, preidx = 0;
        for (int i = 0; i < a; i++) {
            int idx = preidx;
            while (idx < b && v1[i] > v2[idx]) idx++;
            cnt += idx;
            preidx = idx;
        }
        cout << cnt << '\n';
    }

    return 0;
}