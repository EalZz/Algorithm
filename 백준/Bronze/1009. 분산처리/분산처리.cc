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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while (T--) {
        int a, b, ans = 1; cin >> a >> b;
        while (b--) ans = ans * a % 10;

        if (ans == 0) cout << 10 << '\n';
        else cout << ans << '\n';
    }

    return 0;
}