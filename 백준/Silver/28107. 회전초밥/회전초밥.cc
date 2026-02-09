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
queue<int> sushi[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<int> cnt(N, 0);

    for (int i = 0; i < N; i++) {
        int k, a; cin >> k;
        while (k--) {
            cin >> a;
            sushi[a].push(i);
        }
    }

    while (M--) {
        int cur; cin >> cur;
        if (sushi[cur].empty()) continue;

        cnt[sushi[cur].front()]++;
        sushi[cur].pop();
    }

    for (auto c : cnt) cout << c << ' ';

    return 0;
}