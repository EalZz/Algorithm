#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string switch_(string str1);

int main() {
    string num1, num2, snum1, snum2;
    
    cin >> num1 >> num2;

    snum1 = switch_(num1);
    snum2 = switch_(num2);

    if (stoi(snum1) > stoi(snum2)) {
        cout << snum1;
    }
    else {
        cout << snum2;
    }
        
    return 0;
}

string switch_ (string str1) {
    int len = str1.length();
    for (int i = 0; i < len / 2; i++) {
        char ch;
        ch = str1[i];
        str1[i] = str1[len - 1 - i];
        str1[len - 1 - i] = ch;
    }
    return str1;
}