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

    int N, M; cin >> N >> M;
    deque<int> dq(N);
    for (int i = 0; i < N; i++) dq[i] = i + 1;

    int ans = 0;
    while (M--) {
        int target; cin >> target;
        if (dq.front() == target) {
            dq.pop_front();
            continue;
        }

        int size = dq.size(), mid = size / 2;
        int idx = find(dq.begin(), dq.end(), target) - dq.begin();
        
        if (idx <= mid) {
            for (int i = 0; i < idx; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            ans += idx;
        }
        else {
            for (int i = 0; i < size - idx; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            ans += size - idx;
        }
        dq.pop_front();
    }
    cout << ans;

    return 0;
}