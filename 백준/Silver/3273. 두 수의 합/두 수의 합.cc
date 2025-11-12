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
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int x, left = 0, right = n - 1, ans = 0; cin >> x;
    
    while (left < right) {
        int sum = v[left] + v[right];

        if (sum == x) {
            ans++;
            left++;
        }
        else if (sum > x) right--;
        else if (sum < x) left++;
    }

    cout << ans;

    return 0;
}

