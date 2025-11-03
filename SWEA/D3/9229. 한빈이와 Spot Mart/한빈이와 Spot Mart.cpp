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

        int N, M; cin >> N >> M;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int ans = -1;
        int left = 0, right = N - 1;
        while (left < right) {
            int sum = v[left] + v[right];
            if (sum > M) right--;
            else {
                ans = max(ans, sum);
                left++;
            }
        }

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}
