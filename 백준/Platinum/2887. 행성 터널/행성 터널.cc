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

void union_s(int a, int b, vector<int>& parent);
bool isSame(int a, int b, vector<int>& parent);
int find(int x, vector<int>& parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<pair<int, int>> v[3];
    
    for (int i = 0; i < N; i++) {
        int x, y, z; cin >> x >> y >> z;
        v[0].push_back({ x, i });
        v[1].push_back({ y, i });
        v[2].push_back({ z, i });
    }
    vector<int> parent(N + 1);
    for(int i = 0; i < N; i++) parent[i] = i;

    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    sort(v[2].begin(), v[2].end());

    vector<pair<int, pair<int, int>>> cost;
    for (int i = 0; i < N - 1; i++) {
        cost.push_back({ abs(v[0][i].first - v[0][i + 1].first), {v[0][i].second, v[0][i + 1].second} });
        cost.push_back({ abs(v[1][i].first - v[1][i + 1].first), {v[1][i].second, v[1][i + 1].second} });
        cost.push_back({ abs(v[2][i].first - v[2][i + 1].first), {v[2][i].second, v[2][i + 1].second} });
    }
    sort(cost.begin(), cost.end());

    int ans = 0;
    for (int i = 0; i < cost.size(); i++) {
        if (isSame(cost[i].second.first, cost[i].second.second, parent)) continue;
        ans += cost[i].first;
        union_s(cost[i].second.first, cost[i].second.second, parent);
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
    return parent[x] = find(parent[x], parent);
}