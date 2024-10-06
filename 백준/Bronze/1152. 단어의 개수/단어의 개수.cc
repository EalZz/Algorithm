#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str;
    getline(cin, str);

    int len = str.length();
    int cnt = 1;

    for (int i = 0; i < len; i++) {
        if (str[i] == 0x20) {
            cnt++;
        }
    }
    if (str[0] == 0x20) {
        cnt--;
    }
    if (str[len - 1] == 0x20) {
        cnt--;
    }

    cout << cnt << endl;

    return 0;
}