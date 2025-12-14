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

    int N, X, ans = 0, sum = 0, day = 1; cin >> N >> X;
    deque<int> dq;
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        dq.push_back(tmp);
        sum += tmp;

        if (dq.size() > X) {
            sum -= dq.front();
            dq.pop_front();
        }
        if (dq.size() == X) {
            if (ans < sum) {
                ans = sum;
                day = 1;
            }
            else if (ans == sum) day++;
        }
    }

    if (ans != 0) cout << ans << '\n' << day;
    else cout << "SAD";

    return 0;
}