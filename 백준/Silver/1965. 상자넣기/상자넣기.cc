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

void dfs(int idx, int M, set<vector<int>>& s, vector<int>& ans, vector<int>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    vector<int> v(n), lis;
    for (int i = 0; i < n; i++) cin >> v[i];
    lis.push_back(v[0]);

    for (int i = 1; i < n; i++) {
        int val = v[i];
        int pos = lower_bound(lis.begin(), lis.end(), val) - lis.begin();

        if (pos == lis.size()) lis.push_back(val);
        else lis[pos] = val;
    }

    cout << lis.size();

    return 0;
}