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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    long long memo[91];

    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 1;

    for (int i = 3; i <= N; i++) memo[i] = memo[i - 1] + memo[i - 2];

    cout << memo[N];

    return 0;
}