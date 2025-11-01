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

        int N, M, K; cin >> N >> M >> K;
        vector<int> v(N);
        for (int i = 0; i < N; i++) cin >> v[i];
        sort(v.begin(), v.end());

        int count = 0, idx = 0;
        bool isAble = true;
        for (int i = 0; i <= v.back(); i++) {
            if (i % M == 0 && i != 0) count += K;

            if (i == v[idx]) {
                if (count < 1) {
                    isAble = false;
                    break;
                }
                count--;
                idx++;
            }
        }

        cout << '#' << t << ' ';
        if (isAble) cout << "Possible";
        else cout << "Impossible";
        cout << '\n';
    }
    return 0;
}
