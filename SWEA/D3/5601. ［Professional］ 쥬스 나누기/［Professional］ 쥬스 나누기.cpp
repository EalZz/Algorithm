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

        int n; cin >> n;

        cout << "#" << t << " ";
        for (int i = 0; i < n; i++) cout << 1 << '/' << n << ' ';
        cout << '\n';
    }
    return 0;
}