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
int cnt = -1e9, cnt1 = 1e9;
//int memo[21][21][21];
//int memo[10000001];
int calc[4] = { 0, };

void dfs(int idx, int sum, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T);
    //vector<int> tmp;
    //vector<vector<int>> v(a + 1);
    //vector<bool> isVisited(a + 1, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];
    for (int i = 0; i < 4; i++) cin >> calc[i];

    dfs(1, v[0], v);
    cout << cnt << '\n' << cnt1;

    return 0;
}

void dfs(int idx, int sum, vector<int>& v) {
    if (idx == v.size()) {
        cnt = max(cnt, sum);
        cnt1 = min(cnt1, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (calc[i]) {
            calc[i]--;
            if(i == 0) dfs(idx + 1, sum + v[idx], v);
            else if (i == 1) dfs(idx + 1, sum - v[idx], v);
            else if (i == 2) dfs(idx + 1, sum * v[idx], v);
            else if (i == 3) dfs(idx + 1, sum / v[idx], v);
            calc[i]++;
        }
    }

    return;
}
