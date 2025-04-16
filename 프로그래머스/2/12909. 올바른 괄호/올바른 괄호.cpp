#include<string>
#include <iostream>

using namespace std;

bool solution(string s) {
    int check = 0;
    for(auto c : s) {
        if(c == '(') check++;
        else if(c == ')') check--;
        if(check < 0) return false;
    }
    if(check == 0) return true;
    else return false;
}