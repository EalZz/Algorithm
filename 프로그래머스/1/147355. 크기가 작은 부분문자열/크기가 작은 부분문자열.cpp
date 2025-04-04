#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long long ip = stoll(p); 
    
    for (int i = 0; i <= t.size() - p.size(); i++) {
        string sub = t.substr(i, p.size()); // 부분 문자열 추출
        long long num = stoll(sub);    // 문자열을 숫자로 변환
        if (num <= ip) answer++;
    }
    
    return answer;
}