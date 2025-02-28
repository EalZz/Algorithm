#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    
    if (a == b) return a;
    
    long long sum = a + b, count = abs(a - b) - 1, ins = max(a, b) - 1;
    
    while(count--){
        sum += ins;
        ins--;
    }

    return sum;
}