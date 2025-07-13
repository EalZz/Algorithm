#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

int main() {
    int T = 0; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s, rs; cin >> s;
        sort(s.begin(), s.end());

        for (int i = 0; i < s.size(); i++) {
            if (i < s.size() - 1) {
                if (s[i] == s[i + 1]) i++;
                else rs += s[i];
            }
            else rs += s[i];
        }

        cout << "#" << t << " " ;
        if (rs.size()) cout << rs;
        else cout << "Good";
        cout << endl;
    }
    return 0;
}