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

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };

void bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc; cin >> tc;

    while (tc--) {
        int N; cin >> N;

        vector<pair<int, int>> v(N);
        for (int i = 0; i < N; i++) cin >> v[i].first >> v[i].second;
        sort(v.begin(), v.end());

        int cnt = 0, maxs = v[0].second;
        for (int i = 0; i < N; i++) {
            if (v[i].second > maxs) continue;
            cnt++;
            maxs = v[i].second;
        }
        cout << cnt << '\n';
    }

    return 0;
}