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
        
        int N, D; cin >> N >> D;
        int spec = D * 2 + 1;
        int ans = N / spec;
        if (N % spec != 0) ans++;

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}