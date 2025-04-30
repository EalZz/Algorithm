#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> dq(s.begin(), s.end()), chkdq;
    for(int i = 0; i < s.size(); i++) {
        chkdq.clear();
        for(auto d : dq) {
            if (chkdq.empty()) chkdq.push_back(d);
            else if (
                (d == ')' && chkdq.back() == '(') ||
                (d == '}' && chkdq.back() == '{') ||
                (d == ']' && chkdq.back() == '[')
            ) chkdq.pop_back();
            else chkdq.push_back(d);
        }
        if(chkdq.empty()) answer++;
        
        dq.push_back(dq.front());
        dq.pop_front();
    }
    return answer;
}