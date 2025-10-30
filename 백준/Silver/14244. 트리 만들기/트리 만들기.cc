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
int dp[10000][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    
    for (int i = 0; i < n - m; i++) cout << i << ' ' << i + 1 << '\n';
    for (int i = n - m; i < n - 1; i++) cout << n - m << ' ' << i + 1 << '\n';

    return 0;
}