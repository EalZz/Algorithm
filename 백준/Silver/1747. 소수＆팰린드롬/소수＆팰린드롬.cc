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
int cnt = 0;
//int memo[21][21][21];
int memo[10000000];

int PrimePelin(int n);
bool isPrime(int n);
bool isPelin(int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0;

    cout << PrimePelin(T);

    return 0;
}

int PrimePelin(int n) {
    if (memo[n] != -1) return memo[n];

    if (isPrime(n) && isPelin(n)) memo[n] = n;
    else memo[n] = PrimePelin(n + 1);

    return memo[n];
}

bool isPrime(int n) {
    if (n == 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isPelin(int n) {
    string tmp = to_string(n);

    for (int i = 0; i < tmp.length() / 2; i++) {
        if (tmp[i] != tmp[tmp.length() - 1 - i]) return false;
    }
    return true;
}