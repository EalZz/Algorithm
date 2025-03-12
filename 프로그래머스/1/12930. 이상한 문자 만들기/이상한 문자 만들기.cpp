#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string str = s;
    int idx = 0;
    
    for(int i = 0; i < s.size(); i++){
        if (s[i] == ' ') {
            idx = 0;
            continue;
        }
        str[i] = (idx % 2 == 0) ? toupper(str[i]) : tolower(str[i]);
        idx++;
    }
    
    return str;
}