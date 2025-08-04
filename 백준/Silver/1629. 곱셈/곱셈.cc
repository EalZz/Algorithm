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
long long dev(long long a, long long b, long long c);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    //int T = 0; cin >> T;

    cout << dev(a, b, c);

    return 0;
}

long long dev(long long a, long long b, long long c) {
    if (b == 0) return 1;

    long long half = dev(a, b / 2, c);

    half = (half * half) % c;
    if (b % 2) half = half * a % c;

    return half;
}