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

    vector<int> memo(46);
    memo[0] = 0;
    memo[1] = 1;

    for (int i = 2; i <= 45; i++) memo[i] = memo[i - 1] + memo[i - 2];

    int K; cin >> K;
    cout << memo[K - 1] << ' ' << memo[K];

    return 0;
}