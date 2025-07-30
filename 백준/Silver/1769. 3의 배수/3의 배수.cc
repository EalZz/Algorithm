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
string trance(string s);
int cnt = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N = 0, K = 0; 
    //cin >> N >> K;
    string s; cin >> s;

    string result = stoi(trance(s)) % 3 ? "NO" : "YES";
    cout << cnt << '\n' << result;

    return 0;
}

string trance(string s) {
    if (s.size() == 1) return s;

    int sum = 0;
    cnt++;

    for (auto c : s) sum += c - '0';

    return trance(to_string(sum));
}