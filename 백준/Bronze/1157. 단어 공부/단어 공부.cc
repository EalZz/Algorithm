#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    char alphabet_A[26];
    char alphabet_a[26];
    const char* pch = str.c_str();
    int count[26] = { 0, };
    int max = 0, index = 0;
    bool check = false;

    for (int i = 0; i < 26; i++) {
        alphabet_a[i] = 'a' + i;
        alphabet_A[i] = 'A' + i;

        for (int j = 0; j < str.length(); j++) {
            if (pch[j] == alphabet_a[i] || pch[j] == alphabet_A[i]) {
                count[i] += 1;
            }
        }
        //cout << count[i] << " ";
    }
    
    for (int i = 0; i < 26; i++) {
        if (max < count[i]) {
            max = count[i];
            index = i;
            check = false;
        }
        else if (max == count[i]) {
            check = true;
        }
    }
    if (check == true)
        cout << "?" << endl;
    else
        cout << alphabet_A[index] << endl;

    return 0;
}