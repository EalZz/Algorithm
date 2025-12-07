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

    long long X, Y, Z; cin >> X >> Y;
    Z = (Y * 100) / X;

    if (Z >= 99) {
        cout << -1;
        return 0 ;
    }

    long long left = 0, right = 1000000000;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long avg = (Y + mid) * 100 / (X + mid);

        if (Z < avg) right = mid - 1;
        else left = mid + 1;
    }

    cout << left;

    return 0;
}