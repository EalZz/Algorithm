#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    int len = s.length();
    
    if(len % 2 == 0){
        return s.substr(len / 2 - 1, 2);
    }
    else {
        return s.substr(len / 2, 1);
    }
}