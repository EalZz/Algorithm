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
int recursion(const char* s, int l, int r);
int isPalindrome(const char* s);
int cnt = 0;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T = 0; cin >> T;

    for (int i = 0; i < T; i++) {
        string s; cin >> s;
        cnt = 0;
        cout << isPalindrome(s.c_str()) << " " << cnt << '\n';
    }

    return 0;
}

int recursion(const char* s, int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
    return recursion(s, 0, strlen(s) - 1);
}