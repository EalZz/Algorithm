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
        vector<int> v(N);
        for (int i = 0; i < N; i++)cin >> v[i];
        
        int ans = -1;
        for (int i = 0; i < N - 1; i++) {
            for (int j = i + 1; j < N; j++) {
                int mul = v[i] * v[j];
                int post = mul % 10;
                mul /= 10;

                bool isAble = true;
                while (mul > 0) {
                    if (mul % 10 > post) {
                        isAble = false;
                        break;
                    }
                    post = mul % 10;
                    mul /= 10;
                }

                if (isAble) ans = max(ans, v[i] * v[j]);
            }
        }

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}
