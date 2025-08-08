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
int cnt = 0;

void subset(vector<int>& v, int target, int sum, int idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0;

    vector<int> v(T);
    for (int i = 0; i < T; i++) cin >> v[i];

    subset(v, N, 0, 0);
    cout << cnt;

    return 0;
}

void subset(vector<int>& v, int target, int sum, int idx) {
    if (idx == v.size()) return;

    subset(v, target, sum, idx + 1);

    sum += v[idx];
    subset(v, target, sum, idx + 1);

    if (sum == target) cnt++;

    return;
}