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
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());

    long long sum = 0;
    int idx = 0;
    while (idx < N) {
        if (idx % 3 != 2) sum += v[idx];
        idx++;
    }

    cout << sum;

    return 0;
}