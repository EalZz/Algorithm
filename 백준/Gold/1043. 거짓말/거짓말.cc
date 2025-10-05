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
int cnt = 0, cnt1 = 0;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];
long long memo[10001];

int find(int x, vector<int>& p);
void union_s(int a, int b, vector<int>& p);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(N + 1);
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    vector<int> ps(T + 1, 0);
    for (int i = 1; i <= T; i++) ps[i] = i;

    int tp; cin >> tp;
    vector<int> tps(tp);
    for (int i = 0; i < tp; i++) cin >> tps[i];

    vector<vector<int>> pv(N);
    for (int i = 0; i < N; i++) {
        int pp; cin >> pp;
        pv[i].resize(pp);
        for (int j = 0; j < pp; j++) cin >> pv[i][j];
        for (int j = 1; j < pp; j++) union_s(pv[i][0], pv[i][j], ps);
    }

    vector<int> truthps;
    for (auto& p : tps) truthps.push_back(find(p, ps));

    for (int i = 0; i < N; i++) {
        bool isAble = true;
        for (auto& p : pv[i]) {
            int root = find(p, ps);
            for (auto& troot : truthps) {
                if (root == troot) {
                    isAble = false;
                    break;
                }
            }
            if (!isAble) break;
        }
        if (isAble) cnt++;
    }

    cout << cnt;

    return 0;
}

void union_s(int a, int b, vector<int>& p) {
    a = find(a, p);
    b = find(b, p);
    if (a != b) p[b] = a;
}

int find(int x, vector<int>& p) {
    if (p[x] == x) return x;
    return p[x] = find(p[x], p);
}
