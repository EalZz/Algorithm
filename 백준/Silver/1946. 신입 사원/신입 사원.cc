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

    int tc; cin >> tc;
    while (tc--) {
        int N; cin >> N;
        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());

        int ans = 0, maxScore = v[0].second;
        for (int i = 0; i < N; i++) {
            if (v[i].second > maxScore) continue;
            ans++;
            maxScore = v[i].second;
        }

        cout << ans << '\n';
    }

    return 0;
}