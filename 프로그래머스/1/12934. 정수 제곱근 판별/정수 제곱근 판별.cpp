#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    for(long long i = 0; pow(i, 2) <= n; i++){
        if(n == (long long)pow(i, 2)) return (long long)pow(i + 1, 2);
    }
    return -1;
}