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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int n, m; cin >> n >> m;
        vector<int> park(n + 1, 0);
        vector<bool> isVisited(n + 1, false);
        for (int i = 1; i <= n; i++) cin >> park[i];
        vector<int> weight(m + 1, 0);
        for (int i = 1; i <= m; i++) cin >> weight[i];

        int ans = 0, cnt = m;
        map<int, int> where;
        queue<int> order;
        while (1) {
            int cmd; cin >> cmd;

            if (cmd > 0) order.push(cmd);
            if (cmd < 0) {
                isVisited[where[abs(cmd)]] = false;
                where.erase(abs(cmd));
                cnt--;
                if (cnt == 0) break;
            }

            if (order.empty()) continue;

            int curCar = order.front();
            for (int i = 1; i <= n; i++) {
                if (isVisited[i]) continue;

                order.pop();
                isVisited[i] = true;

                ans += park[i] * weight[curCar];
                where[curCar] = i;
                break;
            }
        }

        cout << "#" << t << " ";
        cout << ans;
        cout << '\n';
    }
    return 0;
}