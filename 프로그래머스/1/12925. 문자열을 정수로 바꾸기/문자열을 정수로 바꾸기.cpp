#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string s) {
    int num = 0;
    for(int i = 0; i < s.size() - 1; i++){
        num += pow(10, i) * (s[s.size() - i - 1] - 48);
    }
    if(s[0] == '-') return -num;
    else if(s[0] == '+') return num;
    else return num + pow(10, s.size() - 1) * (s[0] - 48);
}