#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    map<char, char> vm;
    string s1 = "CEFGHIJKLMNSTUVWXYZ", s2 = "ADOPQR";
    for (int i = 'A'; i <= 'Z'; i++) {
        if (s1.find(i) != string::npos) vm[i] = '0';
        else if (s2.find(i) != string::npos) vm[i] = '1';
        else if (i == 'B') vm[i] = '2';
    }

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        string str1, str2; cin >> str1 >> str2;
        string num1, num2;
        for (int i = 0; i < str1.size(); i++) num1.push_back(vm[str1[i]]);
        for (int i = 0; i < str2.size(); i++) num2.push_back(vm[str2[i]]);

        cout << "#" << t << " ";
        if (num1 == num2) cout << "SAME";
        else cout << "DIFF";
        cout << '\n';
    }
    return 0;
}