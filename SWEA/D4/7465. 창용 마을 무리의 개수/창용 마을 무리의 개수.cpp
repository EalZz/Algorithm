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

using namespace std;

void union_s(int a, int b, vector<int>& parent);
bool isSame(int a, int b, vector<int>& parent);
int find(int x, vector<int>& parent);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;
        
        int N, M; cin >> N >> M;
        vector<int> parent(N + 1, 0);
        for (int i = 1; i <= N; i++) parent[i] = i;

        for (int i = 0; i < M; i++) {
            int a, b; cin >> a >> b;
            if (isSame(a, b, parent)) continue;
            union_s(a, b, parent);
        }
        
        set<int> s;
        for (int i = 1; i <= N; i++) s.insert(find(i, parent));

        cout << "#" << t << " ";
        cout << s.size();
        cout << '\n';
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