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

    bool isSelf[10001] = { false, };
    for (int i = 1; i <= 10000; i++) {
        int a = i;
        int sum = 0;
        while (a != 0) {
            sum += a % 10;
            a /= 10;
        }
        if (i + sum <= 10000) isSelf[i + sum] = true;
    }

    for (int i = 1; i <= 10000; i++) {
        if (!isSelf[i]) cout << i << '\n';
    }

    return 0;
}