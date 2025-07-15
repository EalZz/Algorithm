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

    //int N = 0; cin >> N;
    
    while (1) {
        string s; //cin >> s;
        getline(cin, s);
        if (s == ".") return 0;
        stack<char> st;
        bool isVPS = true;

        for (char c : s) {
            if (c == '(' || c == '[') st.push(c);
            else if (c == ')') {
                if (!st.empty() && st.top() == '(') st.pop();
                else {
                    isVPS = false;
                    break;
                }
            }
            else if (c == ']') {
                if (!st.empty() && st.top() == '[') st.pop();
                else {
                    isVPS = false;
                    break;
                }
            }
        }
        if (st.size()) isVPS = false;

        if(isVPS) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }

    return 0;
}
