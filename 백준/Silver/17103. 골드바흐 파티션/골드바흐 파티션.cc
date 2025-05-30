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

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int tmp = 0;
        cin >> tmp;

        vector<int> a;
        for (int j = 2; j < tmp; j++) {
            if (isPrime(j)) a.push_back(j);
        }
        int count = 0;
        int left = 0;
        int right = a.size() - 1;

        while (left <= right) {
            int sum = a[left] + a[right];

            if (sum < tmp) left++;
            else if (sum > tmp) right--;
            else if (sum == tmp) {
                count++;
                left++;
                right--;
            }
        }
        cout << count << "\n";
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

vector<int> sieve() {
    vector<int> A(MAX + 1, 1);
    A[0] = A[1] = 0;

    for (int i = 2; i <= static_cast<int>(sqrt(MAX)); i++) {
        if (A[i] == 0)
            continue;
        for (int j = i * i; j <= MAX; j += i) {
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