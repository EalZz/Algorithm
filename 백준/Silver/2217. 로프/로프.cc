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

    int N, min = 1e9; cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        pq.push(tmp);
    }

    int ans = 0;
    while (!pq.empty()) {
        ans = max(ans, pq.top() * N);
        pq.pop();
        N--;
    }

    cout << ans;

    return 0;
}