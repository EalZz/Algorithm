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

void dfs(int& ans, vector<int>& sum, vector<int>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> v(N), sum;
    for (int i = 0; i < N; i++) cin >> v[i];

    int ans = 0;
    vector<bool> isVisited(N, false);

    dfs(ans, sum, v, isVisited);

    cout << ans;

    return 0;
}

void dfs(int& ans, vector<int>& sum, vector<int>& v, vector<bool>& isVisited) {
    if (sum.size() == v.size()) {
        int tmp = 0;
        for (int i = 0; i < sum.size() - 1; i++) tmp += abs(sum[i] - sum[i + 1]);
        ans = max(ans, tmp);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (isVisited[i]) continue;
        isVisited[i] = true;
        sum.push_back(v[i]);

        dfs(ans, sum, v, isVisited);

        isVisited[i] = false;
        sum.pop_back();
    }
    return;
}