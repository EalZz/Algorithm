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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    vector<int> check(10, 0);

    for (auto& c : s) check[c - '0']++;
    int sixnine = (check[6] + check[9] + 1) / 2;
    check[6] = check[9] = sixnine;

    int ans = 0;
    for (auto& i : check) {
        ans = max(ans, i);
    }

    cout << ans;

    return 0;
}