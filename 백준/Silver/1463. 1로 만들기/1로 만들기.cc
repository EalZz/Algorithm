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
int memo[10000001];
int makeone(int T);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;

    cout << makeone(T);

    return 0;
}

int makeone(int T) {
    if (T == 1) return 0;
    if (memo[T] != -1) return memo[T];

    memo[T] = makeone(T - 1) + 1;
    if (T % 2 == 0) memo[T] = min(memo[T], makeone(T / 2) + 1);
    if (T % 3 == 0) memo[T] = min(memo[T], makeone(T / 3) + 1);
   
    return memo[T];
}
