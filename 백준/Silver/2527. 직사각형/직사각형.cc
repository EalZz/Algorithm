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

    int tc = 4;
    while (tc--) {
        int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
        cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;
        vector<int> ax = { ax1, ax2 };
        vector<int> ay = { ay1, ay2 };
        vector<int> bx = { bx1, bx2 };
        vector<int> by = { by1, by2 };
        sort(ax.begin(), ax.end());
        sort(ay.begin(), ay.end()); 
        sort(bx.begin(), bx.end());
        sort(by.begin(), by.end());

        if (ax[0] > bx[1] || ax[1] < bx[0] ||
            ay[0] > by[1] || ay[1] < by[0])
            cout << 'd' << '\n';

        else if ((ax[1] == bx[0] && ay[1] == by[0]) ||
            (ax[0] == bx[1] && ay[1] == by[0]) ||
            (ax[1] == bx[0] && ay[0] == by[1]) ||
            (ax[0] == bx[1] && ay[0] == by[1]))
            cout << 'c' << '\n';
        
        else if (ax[1] == bx[0] || ax[0] == bx[1] ||
            ay[1] == by[0] || ay[0] == by[1])
            cout << 'b' << '\n';

        else cout << 'a' << '\n';
    }

    return 0;
}