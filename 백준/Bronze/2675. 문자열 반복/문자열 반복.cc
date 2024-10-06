#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    string str;

    //실험 반복
    for (int i = 0; i < n; i++) {
        int repeat = 0;
        cin >> repeat;

        cin >> str;
        const char* pch = str.c_str();

        //실험1 : 각 글자만큼 반복
        for (int j = 0; j < str.size(); j++) {
            //실험2 : 각 글자를 repeat만큼 반복
            for (int k = 0; k < repeat; k++) {
                cout << pch[j];
            }
        }
        cout << endl;
    }
    return 0;
}