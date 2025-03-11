#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    int i = 0;
    while(i < seoul.size()){
        if(seoul[i] == "Kim") break;
        i++;
    }
    return "김서방은 " + to_string(i) + "에 있다";
}