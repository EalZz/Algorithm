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
string cantor(int T);

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T = 0;
    while (cin >> T)  cout << cantor(T) << "\n";

    return 0;
}

string cantor(int T) {
    if (T == 0) return "-";
    else {
        string s = cantor(T - 1);
        s += string(pow(3, T - 1), ' ');
        s += cantor(T - 1);
        return s;
    }
}