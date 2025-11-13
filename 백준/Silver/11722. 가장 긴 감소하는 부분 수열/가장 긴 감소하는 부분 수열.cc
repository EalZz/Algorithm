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

    int N; cin >> N;
    vector<int> lis;
    for (int i = 0; i < N; i++) {
        int val; cin >> val;
        val = -val;
        int pos = lower_bound(lis.begin(), lis.end(), val) - lis.begin();

        if (pos == lis.size()) lis.push_back(val);
        else lis[pos] = val;
    }

    cout << lis.size();

    return 0;
}