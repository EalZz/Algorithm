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

    int N, Q; cin >> N >> Q;

    vector<set<int>> v(N + 1);
    for (int i = 1; i <= N; i++) {
        int M; cin >> M;
        for (int j = 0; j < M; j++) {
            int tmp; cin >> tmp;
            v[i].insert(tmp);
        }
    }

    while (Q--) {
        int cmd; cin >> cmd;
        
        if (cmd == 2) {
            int i; cin >> i;
            cout << v[i].size() << '\n';
            continue;
        }

        int i, j; cin >> i >> j;
        if (v[i].size() < v[j].size()) swap(v[i], v[j]);
        for (auto& num : v[j]) v[i].insert(num);
        v[j].clear();
    }
      
    return 0;
}
