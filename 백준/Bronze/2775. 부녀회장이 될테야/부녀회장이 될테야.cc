#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
long long gcd(long long a, long long b);
bool isPrime(long long int num);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a[15][15];
    for (int i = 0; i < 15; i++) {
        a[0][i] = i;
        a[i][0] = 0;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 1; j < 15; j++) {
            a[j][i] = a[j - 1][i] + a[j][i - 1];
        }
    }
    int t = 0, k = 0, n = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> k >> n;
        cout << a[k][n] << "\n";
    }
    
    return 0;
}