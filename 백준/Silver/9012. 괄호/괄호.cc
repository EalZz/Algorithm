#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        stack<char> st;
        bool isVPS = true;

        for (char c : s) {
            if (c == '(') st.push(c);
            else {
                if (st.empty()) {
                    isVPS = false;
                    break;
                }
                st.pop();
            }
        }
        if (st.size()) isVPS = false;

        if(isVPS) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }

    return 0;
}
