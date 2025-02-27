#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    return (s.length() % 2 == 0) ? s.substr(s.length() / 2 - 1, 2) : s.substr(s.length() / 2, 1);
}