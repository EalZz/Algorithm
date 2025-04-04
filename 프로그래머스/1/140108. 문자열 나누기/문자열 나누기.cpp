#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool change = false;
    char tmp = s[0]; 
    int cntx = 1, cnta = 0; //첫문자와 카운트 +1
    
    //문자열 길이가 1이면 1 반환
    if (s.size() == 1) return 1; 
    
    for(int i = 1; i < s.size(); i++) {
        //문자열을 새로 끊을 때
        if(change){
            tmp = s[i];
            cntx = 0;
            cnta = 0;
            change = false;
        }
        
        //각각 카운트에 추가
        if(s[i] == tmp) cntx++;
        else cnta++;
        
        //카운트가 같아지면 answer++ 후 문자열 끊기
        if(cntx == cnta) {
            answer++;
            change = true;
            continue;
        }
        //마지막까지 카운트가 안맞으면 1추가
        if(i == s.size() - 1) answer++;
    }
    return answer;
}