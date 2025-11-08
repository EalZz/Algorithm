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

        string s; cin >> s;
        int maxv, minv;
        maxv = minv = stoi(s);

        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if(i == 0 && s[j] == '0') continue;
                swap(s[i], s[j]);
                maxv = max(maxv, stoi(s));
                minv = min(minv, stoi(s));
                swap(s[i], s[j]);
            }
        }

        cout << "#" << t << " ";
        cout << minv << ' ' << maxv;
        cout << '\n';
    }
    return 0;
}