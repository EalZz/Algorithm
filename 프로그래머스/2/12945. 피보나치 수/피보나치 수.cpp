#include <string>
#include <vector>

using namespace std;

int Fibonacci(int n);
int memoization[100000];

int solution(int n) {
    return Fibonacci(n) ;
}

int Fibonacci(int n) {
    if(n == 0) return memoization[n];
    else if(n == 1) {
        if(!memoization[n]) memoization[n] = 1;
        return memoization[n];
    }
    
    //모듈러 산술 (오버플로우 방지를 위해 %1234567을 매번 적용)
    if(!memoization[n]) memoization[n] = (Fibonacci(n - 1) + Fibonacci(n - 2)) % 1234567;
    return memoization[n];
}