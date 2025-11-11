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

int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pq.push(x);
    }

    int ans = 0;
    while (pq.size() != 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int tmp = a + b;
        ans += tmp;
        pq.push(tmp);
    }

    cout << ans;

    return 0;
}

