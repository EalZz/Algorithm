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

    int K; cin >> K;

    int maxX = 0, maxY = 0;
    vector<pair<int, int>> order(6);
    for (int i = 0; i < 6; i++) {
        int dir, len; cin >> dir >> len;

        order[i] = { dir, len };
        if (dir == 1 || dir == 2) maxX = max(maxX, len);
        if (dir == 3 || dir == 4) maxY = max(maxY, len);
    }

    deque<int> dq;
    int idx = 0;
    pair<int, int> sub;
    while (1) {
        if (idx == 6) idx = 0;

        if (dq.size() == 3 && order[dq[0]].first == order[dq[2]].first && order[dq[1]].first == order[idx].first) {
            sub = { dq[1], dq[2]};
            break;
        }

        if(dq.size() == 3) dq.pop_front();
        dq.push_back(idx);
        idx++;
    }

    cout << (maxX * maxY - order[sub.first].second * order[sub.second].second) * K;

    return 0;
}
