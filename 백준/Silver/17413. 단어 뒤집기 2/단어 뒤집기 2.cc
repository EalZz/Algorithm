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
    cout.tie(0);

    string s, tmp; getline(cin, s);
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '<') {
            if (tmp != "") {
                reverse(tmp.begin(), tmp.end());
                cout << tmp;
                tmp = "";
            }
            
            while (s[i] != '>') {
                tmp.push_back(s[i]);
                i++;
            }

            tmp.push_back(s[i]);
            cout << tmp;
            tmp = "";
            continue;
        }
        
        if (s[i] == ' ') {
            reverse(tmp.begin(), tmp.end());
            cout << tmp << ' ';
            tmp = "";
            continue;
        }
        tmp.push_back(s[i]);
    }

    if (tmp[0] == '<') cout << tmp;
    else {
        reverse(tmp.begin(), tmp.end());
        cout << tmp;
    }

    return 0;
}