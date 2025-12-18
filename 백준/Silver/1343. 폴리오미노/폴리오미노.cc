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

    string s, ans = ""; cin >> s;
    int cnt = 0;

    for (auto& c : s) {
        if (c == '.') {
            if (cnt % 2) {
                cout << -1;
                return 0;
            }

            while (cnt > 0) {
                if (cnt >= 4) {
                    ans += "AAAA";
                    cnt -= 4;
                }
                else {
                    ans += "BB";
                    cnt -= 2;
                }
            }
            ans += ".";
        }
        else cnt++;
    }
    if (cnt % 2 == 1) {
        cout << -1;
        return 0;
    }
    while (cnt > 0) {
        if (cnt >= 4) {
            ans += "AAAA";
            cnt -= 4;
        }
        else {
            ans += "BB";
            cnt -= 2;
        }
    }


    cout << ans;

    return 0;
}