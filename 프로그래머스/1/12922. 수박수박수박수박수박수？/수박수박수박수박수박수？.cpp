#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string s;
    for(int i = 1; i <= n; i++) s += (i % 2 == 0) ? "박" : "수";
    return s;
}