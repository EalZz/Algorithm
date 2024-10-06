#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    cin >> str;
    char alphabet[26];
    int count[26] = {0, };

    for (int i = 0; i < 26; i++) {
        alphabet[i] = 'a' + i;

        if (str.find(alphabet[i]) != string::npos) {
            count[i] += str.find(alphabet[i]);
        }
        else {
            count[i] = -1;
        }
        cout << count[i] << " ";
    }

    return 0;
}