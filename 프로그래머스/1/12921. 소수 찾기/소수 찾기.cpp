#include <vector>
#include <cmath>

int solution(int n) {
    if (n <= 1) return 0;
    
    std::vector<bool> isPrime(n + 1, true);
    
    isPrime[0] = isPrime[1] = false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            count++;
        }
    }
    
    return count;
}