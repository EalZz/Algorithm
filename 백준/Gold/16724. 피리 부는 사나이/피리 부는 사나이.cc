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

    int N, M; cin >> N >> M;
    vector<int> edge(N * M), parent(N * M);
    string tmp;
    for (int row = 0; row < N; row++) {
        cin >> tmp;
        for (int col = 0; col < M; col++) {
            int idx = row * M + col;
            if (tmp[col] == 'U') idx -= M;
            if (tmp[col] == 'D') idx += M;
            if (tmp[col] == 'L') idx -= 1;
            if (tmp[col] == 'R') idx += 1;
            edge[row * M + col] = idx;
            parent[row * M + col] = row * M + col;
        }
    }

    for (int i = 0; i < edge.size(); i++) {
        if (isSame(parent[i], edge[i], parent)) continue;
        union_s(parent[i], edge[i], parent);
    }

    set<int> s;
    for (int i = 1; i < parent.size(); i++) {
        s.insert(find(i, parent));
    }

    cout << s.size();

    return 0;
}

void union_s(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
}

bool isSame(int a, int b, vector<int>& parent) {
    return find(a, parent) == find(b, parent);
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return  parent[x] = find(parent[x], parent);
}