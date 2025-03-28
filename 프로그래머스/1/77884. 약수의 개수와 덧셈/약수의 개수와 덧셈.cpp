#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++) {
        int isSquare = sqrt(i);
        if(sqrt(i) == isSquare) answer -= i;
        else answer += i;
    }
    return answer;
}