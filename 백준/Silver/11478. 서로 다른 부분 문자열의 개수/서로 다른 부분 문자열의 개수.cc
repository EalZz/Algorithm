#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string str;
    cin >> str;
    int len = str.length();
    set<string> str2;
        
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j + i <= len; j++) {
            str2.insert(str.substr(j, i));
        }
    }

    cout << str2.size() << "\n";

    return 0;
}