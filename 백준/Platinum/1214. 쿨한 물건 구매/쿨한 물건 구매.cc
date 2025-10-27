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
const long long INF = 1e15;
long long memo[10001][21];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int D, P, Q; cin >> D >> P >> Q;
    if (D % P == 0 || D % Q == 0) {
        cout << D;
        return 0;
    }
    if (P < Q) swap(P, Q);

    long long ans = (D / P) * P + P;
    long long tmpa = ans;

    for (int i = 1; i <= tmpa / P; i++) {
        long long cur = tmpa - (P * i);
        
        if ((D - cur) % Q == 0) {
            cout << D;
            return 0;
        }

        cur += ((D - cur) / Q) * Q + Q;
        if (ans == cur) break;
        ans = min(ans, cur);
    }

    cout << ans;

    return 0;
}
