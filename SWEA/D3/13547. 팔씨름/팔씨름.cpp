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
        sort(s.begin(), s.end());

        int xcnt = s.size() - (upper_bound(s.begin(), s.end(), 'o') - lower_bound(s.begin(), s.end(), 'o'));

        cout << "#" << t << " ";
        if (xcnt <= 7) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}