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

    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        int tc; cin >> tc;

        string s; cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }

            if (s[i] == ')' && st.top() == '(') st.pop();
            else if (s[i] == ']' && st.top() == '[') st.pop();
            else if (s[i] == '}' && st.top() == '{') st.pop();
            else if (s[i] == '>' && st.top() == '<') st.pop();
            else st.push(s[i]);
        }

        cout << "#" << t << " ";
        if (st.empty()) cout << 1;
        else cout << 0;
        cout << '\n';
    }
    return 0;
}
