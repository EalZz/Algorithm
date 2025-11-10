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

    int N; cin >> N;
    vector<int> v(N), ans(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    stack<int> st;
    for (int i = N - 1; i >= 0; i--) {
        while (!st.empty()) {
            if (st.top() <= v[i]) st.pop();
            else {
                ans[i] = st.top();
                break;
            }
        }
        if (st.empty()) ans[i] = -1;
        st.push(v[i]);
    }

    for (auto& i : ans) cout << i << ' ';

    return 0;
}