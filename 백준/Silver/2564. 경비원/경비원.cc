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

int swt(int x, int y, int N, int loca);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int x, y, num; cin >> x >> y >> num;
    vector<pair<int, int>> v(num);
    map<int, int> m;
    m[1] = 0; m[4] = 1; m[2] = 2; m[3] = 3;
    for (int i = 0; i < num; i++) {
        int a, b; cin >> a >> b;
        v[i] = { m[a], b };
    }
    int N, cloca; cin >> N >> cloca;
    N = m[N];
    cloca = swt(x, y, N, cloca);
    int rloca = (N % 2 == 1) ? y - cloca : x - cloca;

    int sum = 0;
    for (auto& p : v) {
        int curN = p.first;
        int curCloca = swt(x, y, curN, p.second);
        int curRloca = (curN % 2 == 1) ? y - curCloca : x - curCloca;
        
        if (N == curN) sum += abs(cloca - curCloca);
        else if (abs(N - curN) % 2 == 1) {
            if (N - curN == -1 || N - curN == 3) sum += (cloca + curRloca);
            else sum += (rloca + curCloca);
        }
        else {
            if (N % 2 == 1) sum += (x + min(cloca + curRloca, rloca + curCloca));
            else sum += (y + min(cloca + curRloca, rloca + curCloca));
        }
    }

    cout << sum;

    return 0;
}

int swt(int x, int y, int N, int loca) {
    if (N == 0) return x - loca;
    if (N == 1) return y - loca;
    return loca;
}