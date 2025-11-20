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
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<pair<int, pair<int, int>>> edge(M);
    vector<int> parent(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edge[i] = { cost, {a, b} };
    }
    sort(edge.begin(), edge.end());
    for (int i = 1; i <= N; i++) parent[i] = i;

    int ans = 0;
    for (int i = 0; i < M; i++) {
        int cost = edge[i].first;
        int a = edge[i].second.first;
        int b = edge[i].second.second;
        if (!isSame(a, b, parent)) {
            ans += cost;
            union_s(a, b, parent);
        }
    }

    cout << ans;

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
    return x = find(parent[x], parent);
}

