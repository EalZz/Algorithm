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
        vector<int> v(N + M + 1, 0);

        int cnt = 0;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                v[i + j]++;
                cnt = max(cnt, v[i + j]);
            }
        }
        
        cout << "#" << t << " ";
        for (int i = 2; i <= N + M; i++) {
            if (v[i] == cnt) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}