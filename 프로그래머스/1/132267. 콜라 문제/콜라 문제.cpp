#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a) {
        answer += n / a * b;   //교환한 수
        n = n / a * b + n % a; //교환한 수 + 교환에 사용하지 않은 병 수
    }
    return answer;
}