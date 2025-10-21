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

    int N, K, cost; cin >> N >> K;
    vector<pair<int, int>> v(N);
    vector<int> bag(K);
    for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < K; i++) cin >> bag[i];
    sort(v.begin(), v.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;

    int idx = 0;
    long long ans = 0;
    for (int i = 0; i < K; i++) {
        while (idx < N && bag[i] >= v[idx].first) {
            pq.push(v[idx].second);
            idx++;
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}
