#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i - 1] == ' ') {
            if (s[i] >= 'a' && s[i] <= 'z') answer.push_back(s[i] - 32);
            else answer.push_back(s[i]);
        } 
        else {
            if (s[i] >= 'A' && s[i] <= 'Z') answer.push_back(s[i] + 32);
            else answer.push_back(s[i]);
        }
    }
    return answer;
}
