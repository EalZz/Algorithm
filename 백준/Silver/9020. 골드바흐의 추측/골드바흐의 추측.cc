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

    vector<bool> isPrime(10001, true);

    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= 100; i++) {
        if (!isPrime[i]) continue;
        for (int j = i * 2; j <= 10000; j += i) isPrime[j] = false;
    }

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = n / 2; i > 0; i--) {
            if (!isPrime[i] || !isPrime[n - i]) continue;
            cout << i << ' ' << n - i << '\n';
            break;
        }
    }

    return 0;
}