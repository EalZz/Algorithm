#include <iostream>
#include <cmath>

using namespace std;
int solution(int n)
{
    int answer = 0, cnt = 1;
    
    for(int i = n; i > 0; i /= 10) cnt++;
    
    while(cnt--){
        int num = n / pow(10, cnt - 1);
        answer += num;
        n -=  num * pow(10, cnt - 1);
    }
        
    return answer;
}