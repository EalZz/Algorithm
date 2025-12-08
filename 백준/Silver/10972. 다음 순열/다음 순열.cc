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

    if (next_permutation(v.begin(), v.end()) == true) {
        for (auto& i : v) cout << i << ' ';
    }
    else cout << -1;

    return 0;
}