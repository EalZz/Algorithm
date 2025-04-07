#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<bool> is_skip(26, false);

    //skip에 있는 알파벳 true
    for(char c : skip) is_skip[c - 'a'] = true;
    
    for(char c : s) {
        int cnt = 0;
        while(cnt < index) {
            c++;
            if(c > 'z') c = 'a';  
            if(is_skip[c - 'a']) continue;
            cnt++;
        }
        answer.push_back(c);
    }

    return answer;
}
