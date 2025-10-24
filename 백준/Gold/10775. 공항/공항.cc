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
int find(int x, vector<int>& parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    vector<int> parent(N + 1, 0);
    for (int i = 1; i <= N; i++) parent[i] = i;

    while (M--) {
        int num; cin >> num;

        if (find(num, parent) == 0) break;
        
        cnt++;
        union_s(find(num, parent) - 1, find(num, parent), parent);
    }

    cout << cnt;

    return 0;
}

void union_s(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) parent[b] = a;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return  parent[x] = find(parent[x], parent);
}