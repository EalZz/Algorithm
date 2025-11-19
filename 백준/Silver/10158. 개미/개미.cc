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

    int w, h; cin >> w >> h;
    int x, y, time; cin >> x >> y >> time;

    x = (x + time) % (2 * w);
    if (x > w) x = 2 * w - x;

    y = (y + time) % (2 * h);
    if (y > h) y = 2 * h - y;

    cout << x << ' ' << y;

    return 0;
}