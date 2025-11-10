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

        int K, ans = 0; cin >> K;

        stack<int> st;
        while (K--) {
            int tmp; cin >> tmp;
            if (tmp == 0) st.pop();
            else st.push(tmp);
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}