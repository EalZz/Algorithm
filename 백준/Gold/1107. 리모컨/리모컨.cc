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

    int N, M; cin >> N >> M;
    vector<bool> isBroken(10, false);
    while (M--) {
        int tmp; cin >> tmp;
        isBroken[tmp] = true;
    }

    int ans = abs(N - 100);

    for (int i = 0; i <= 1000000; i++) {
        string s = to_string(i);

        bool isAble = true;
        for (auto& c : s) {
            if (!isBroken[c - '0']) continue;
            isAble = false;
            break;
        }

        if (!isAble) continue;
        ans = min(ans, int(abs(N - i) + s.size()));
    }

    cout << ans;

    return 0;
}