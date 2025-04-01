#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while (n >= a) {
        int newc = (n / a) * b;  // 교환으로 받는 병
        int remain = n % a;      // 교환 후 남는 병
        answer += newc;          // 교환한 총 수
        n = newc + remain;       // 총 병의 갯수
    }
    
    return answer;
}