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
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

void union_s(int a, int b, vector<int>& parent);
bool isSame(int a, int b, vector<int>& parent);
int find(int x, vector<int>& parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, K; cin >> N >> M >> K;
    vector<int> gift(N + 1 , 0), parent(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> gift[i];
        parent[i] = i;
    }
    vector<vector<int>> v(N + 1);
    for (int i = 0; i < M; i++) {
        int s, e; cin >> s >> e;
        v[s].push_back(e);
        v[e].push_back(s);
    }

    for (int i = 1; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (isSame(i, v[i][j], parent)) continue;
            union_s(i, v[i][j], parent);
        }
    }

    map<int, int> group, result;
    for (int i = 1; i < parent.size(); i++) {
        find(i, parent);
        group[parent[i]]++;
        result[parent[i]] += gift[i];
    }

    int dp[10001];
    memset(dp, 0, sizeof(dp));
    for (auto& g : group) {
        int key = g.first;
        int size = g.second;
        int sum = result[key];

        if (size >= K) continue;

        for (int i = K - 1; i >= size; i--) dp[i] = max(dp[i], dp[i - size] + sum);
    }

    cout << dp[K - 1];

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