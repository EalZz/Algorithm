#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool change = false;
    char tmp = s[0];
    int cntx = 1, cnta = 0;
    
    if (s.size() == 1) return 1;
    
    for(int i = 1; i < s.size(); i++) {
        if(change){
            tmp = s[i];
            cntx = 0;
            cnta = 0;
            change = false;
        }
            
        if(s[i] == tmp) cntx++;
        else cnta++;
        
        if(cntx == cnta) {
            answer++;
            change = true;
            continue;
        }
        if(i == s.size() - 1) answer++;
    }
    return answer;
}