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

    string s; cin >> s;

    char pre = s[0];
    int cnt = 0;
    for (int i = 1; i < s.size(); i++) {
        if (pre == s[i]) continue;
        cnt++;
        pre = s[i];
    }

    int ans = (cnt % 2 == 0) ? cnt / 2 : cnt / 2 + 1;
    cout << ans;

    return 0;
}