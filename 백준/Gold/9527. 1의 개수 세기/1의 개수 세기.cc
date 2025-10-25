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
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

long long getOne(long long x, vector<long long> pow2);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long A, B;
    cin >> A >> B;

    vector<long long> pow2(55);
    pow2[0] = 1;
    for (int i = 1; i < 55; i++) {
        pow2[i] = 2 * pow2[i - 1] + (1LL << i);
    }

    cout << getOne(B, pow2) - getOne(A - 1, pow2);
    return 0;
}

long long getOne(long long x, vector<long long> pow2) {
    if (x < 0) return 0;
    long long res = x & 1;

    for (int i = 54; i > 0; i--) {
        if (x & (1LL << i)) {
            res += pow2[i - 1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
    }
    return res;
}