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
        int xcnt = count(s.begin(), s.end(), 'x');

        cout << "#" << t << " ";
        if (xcnt <= 7) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}