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

    int N, M; cin >> N >> M;
    vector<bool> isBroken(11, false);
    for (int i = 0; i < M; i++) {
        int btn; cin >> btn;
        isBroken[btn] = true;
    }

    int ans = abs(N - 100);

    int pre = 1e9;
    for (int i = 0; i <= 1000000; i++) {
        string ch = to_string(i);
        bool isAble = true;
        for (auto c : ch) {
            if (isBroken[c - '0']) {
                isAble = false;
                break;
            }
        }
        if (!isAble) continue;
        int tmp = ch.size() + abs(N - i);
        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}