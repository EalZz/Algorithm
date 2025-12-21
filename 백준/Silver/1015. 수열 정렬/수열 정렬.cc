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

    int N; cin >> N;
    vector<pair<int, int>> v(N);
    vector<int> ans(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < N; i++) ans[v[i].second] = i;
    
    for (auto& a : ans) cout << a << ' ';

    return 0;
}