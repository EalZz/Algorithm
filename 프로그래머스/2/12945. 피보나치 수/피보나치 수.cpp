#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1, tmp1 = 1, tmp2 = 0;
    while(--n) {
        answer = (tmp1 + tmp2) % 1234567;
        tmp2 = tmp1;
        tmp1 = answer;
    }
    return answer;
}