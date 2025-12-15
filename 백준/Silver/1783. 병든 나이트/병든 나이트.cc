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

    int N, M, ans = 0; cin >> N >> M;

    if (N == 1) ans = 1;
    else if (N == 2) ans = min(4, (M - 1) / 2 + 1);
    else {
        if (M >= 7) ans = M - 2;
        else ans = min(4, M);
    }

    cout << ans;

    return 0;
}