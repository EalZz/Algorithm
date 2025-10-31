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

    int A, B, D; cin >> A >> B >> D;

    bool prime[4000001];
    fill(prime, prime + 4000001, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i <= sqrt(B); i++) {
        if (!prime[i]) continue;
        for (int j = i * 2; j <= B; j += i) prime[j] = false;
    }

    vector<string> v;
    for (int i = A; i <= B; i++) {
        if (prime[i]) v.push_back(to_string(i));
    }
    string d = to_string(D);

    int ans = 0;
    for (auto s : v) {
        if (s.find(d) == string::npos) continue;
        ans++;
    }

    cout << ans;

    return 0;
}