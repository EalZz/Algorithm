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

        int a, b, c; 
        cin >> a >> b >> c;

        cout << "#" << t << " ";
        if (a == b) cout << c;
        else {
            if (b == c) cout << a;
            else cout << b;
        }
        cout << '\n';
    }
    return 0;
}