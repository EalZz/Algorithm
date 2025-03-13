#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string phone_number) {
    /*
    string ask;
    int cnt = phone_number.size() - 4;
    while(cnt--) ask.push_back('*');
    
    phone_number.replace(phone_number.begin(), phone_number.end() - 4, ask);
    */
    
    for(int i = 0; i < phone_number.size() - 4; i++) phone_number[i] = '*';
    
    return phone_number;
}