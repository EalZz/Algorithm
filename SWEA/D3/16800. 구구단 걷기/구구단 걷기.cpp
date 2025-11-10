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

        long long N; cin >> N;
        
        long long x, y;
        for (long long i = sqrt(N); i > 0; i--) {
            if (N % i != 0) continue;
            x = i;
            break;
        }
        y = N / x;

        cout << "#" << t << " ";
        cout << x + y - 2;
        cout << '\n';
    }
    return 0;
}