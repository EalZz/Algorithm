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
    vector<pair<tuple<int, int, int>, string>> v(N);

    for (int i = 0; i < N; i++) {
        string name; cin >> name;
        int d, m, y; cin >> d >> m >> y;

        v[i].first = make_tuple(y, m, d);
        v[i].second = name;
    }

    sort(v.begin(), v.end());

    cout << v.back().second << '\n'
        << v.front().second;

    return 0;
}