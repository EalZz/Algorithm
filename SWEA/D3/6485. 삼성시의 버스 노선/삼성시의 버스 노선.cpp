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
        int N; cin >> N;
        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;

        int P; cin >> P;
        vector<int> ans;
        while (P--) {
            int C, cnt = 0; cin >> C;

            for (auto& p : v) {
                if (C >= p.first && C <= p.second) cnt++;
            }
            ans.push_back(cnt);
        }

        cout << '#' << t << ' ';
        for (auto& i : ans) cout << i << ' ';
        cout << '\n';
    }
    return 0;
}