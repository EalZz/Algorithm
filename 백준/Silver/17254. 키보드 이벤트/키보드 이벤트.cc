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
int dp[10000][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    
    vector<tuple<int, int, char>> v(M);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        char c; cin >> c;
        v[i] = { a, b, c };
    }
    sort(v.begin(), v.end(), [](tuple<int, int, char> a, tuple<int, int, char> b) {
        if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
        return get<1>(a) < get<1>(b);
        });

    string ans;
    for (auto& t : v) ans.push_back(get<2>(t));

    cout << ans;

    return 0;
}