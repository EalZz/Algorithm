#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, int n) {
    string answer = s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 32) continue; // 공백은 패스
        char st = (s[i] >= 'a' && s[i] <= 'z') ? 'a' : 'A'; //기준 문자, 대소문자 구분
        answer[i] = st + (s[i] - st + n) % 26; //알파벳 순환
    }
    return answer;
}