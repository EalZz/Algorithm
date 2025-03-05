#include <string>
#include <iostream>
#include <cctype>

using namespace std;

bool solution(string s)
{
    int p_cnt = 0, y_cnt = 0;
    
    for(int i = 0; i < s.size(); i++) {
        char c = toupper(s[i]);
        if (c == 'P') p_cnt++;
        if (c == 'Y') y_cnt++;
    }

    return p_cnt == y_cnt; 
}