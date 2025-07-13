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
        string s; cin >> s;
        vector<int> v;
        int cnt = 0; cin >> cnt;


        while (cnt--) {
            int tmp = 0; cin >> tmp;
            v.push_back(tmp);
        }
        sort(v.begin(), v.end(), greater<int>());

        for (int i = 0; i < v.size(); i++) s.insert(v[i], "-");

        cout << "#" << t << " " << s << endl ;
    }
    return 0;
}