#include <string>
#include <vector>
#include <iostream>

using namespace std;
int coke(int a, int b, int n);

int solution(int a, int b, int n) {
    /*
    while (n >= a) {
        answer += n / a * b;   //교환한 수
        n = n / a * b + n % a; //교환한 수 + 교환에 사용하지 않은 병 수
    }
    */
    return coke(a, b, n);
}

int coke(int a, int b, int n) {
    if (n < a) return 0;
    int new_coke = (n / a) * b;
    return new_coke + coke(a, b, new_coke + n % a);
}
