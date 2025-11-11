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

void union_s(int a, int b, vector<int>& parent);
bool isSame(int a, int b, vector<int>& parent);
int find(int x, vector<int>& parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> v(n + 1);
    for (int i = 0; i <= n; i++) v[i] = i;

    while (m--) {
        int cmd, a, b; cin >> cmd >> a >> b;
        if (cmd == 0) union_s(a, b, v);
        else {
            if (isSame(a, b, v)) cout << "YES" << '\n';
            else cout << "NO" << '\n';
        }
    }

    return 0;
}

void union_s(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
    return;
}

bool isSame(int a, int b, vector<int>& parent) {
    return find(a, parent) == find(b, parent);
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}