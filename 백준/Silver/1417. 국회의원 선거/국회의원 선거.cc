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

    int N; cin >> N;
    priority_queue<int> pq; 

    int one; cin >> one;
    N--;

    while (N--) {
        int tmp; cin >> tmp;
        if (tmp >= one) pq.push(tmp);
    }

    int ans = 0;
    while (!pq.empty() && one <= pq.top()) {
        int t = pq.top();
        pq.pop();
        t--;
        one++;
        ans++;
        pq.push(t);
    }

    cout << ans;

    return 0;
}
