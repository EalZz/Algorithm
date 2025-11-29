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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L; cin >> N >> L;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int cnt = 1, node = v[0];
    for (int i = 1; i < N; i++) {
        if (v[i] - node < L) continue;
        cnt++;
        node = v[i];
    }

    cout << cnt;

    return 0;
}