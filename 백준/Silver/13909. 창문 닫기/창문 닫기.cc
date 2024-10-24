#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
const int MAX = 1000000;
using namespace std;
long long gcd(long long a, long long b);
bool isPrime(int num);
vector<int> sieve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    int count = static_cast<int>(sqrt(n));

    cout << count << "\n";

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

vector<int> sieve() { //에라토스 테네스의 체 (소수면 true, 아니면 false)
    vector<int> A(MAX + 1, 1);
    A[0] = A[1] = 0; // 0과 1은 소수가 아님

    for (int i = 2; i <= static_cast<int>(sqrt(MAX)); i++) {
        if (A[i] == 0) 
            continue;
        for (int j = i * i; j <= MAX; j += i) { //소수의 배수 잘라내기
            A[j] = 0; 
        }
    }

    return A; 
}

bool isPrime(int num) { 
    static vector<int> A = sieve(); 
    if (A[num] == 0) return false;
    else return true;
}