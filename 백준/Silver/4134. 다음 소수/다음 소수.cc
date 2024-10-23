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

    int n = 0;
    cin >> n;

    while (n--) {
        long long int a = 0;
        cin >> a;

        if (a < 2) a = 2;

        while (!isPrime(a)) {
            a++;
        }
        cout << a << "\n";
    }

    return 0;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
bool isPrime(long long int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    long long int limit = static_cast<long long int>(sqrt(num));
    for (long long int j = 3; j <= limit; j += 2) {
        if (num % j == 0) return false;
    }
    return true;
}