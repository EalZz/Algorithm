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

using namespace std;

void dfs(int node, vector<char>& value, vector<vector<int>>& edge);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int a, b, n; cin >> a >> b >> n;

        int cnt = 1;
        while (a + b <= n) {
            if (a < b) a += b;
            else b += a;
            cnt++;
        }

        //cout << "#" << t << " ";
        cout << cnt;
        cout << '\n';
    }
    return 0;
}