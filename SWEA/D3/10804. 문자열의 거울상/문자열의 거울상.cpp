#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int T = 0; cin >> T;
    for (int i = 1; i <= T; i++) {
        string s, rs; cin >> s;
        map<char, char> m;
        m.insert({ 'p', 'q'}); m.insert({ 'q', 'p' });
        m.insert({ 'b', 'd' }); m.insert({ 'd', 'b' });

        for (int j = s.size() - 1; j >= 0; j--) rs.push_back(m[s[j]]);
    
        cout << "#" << i << " " << rs << endl;
    }
    return 0;
}