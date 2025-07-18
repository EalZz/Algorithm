#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
long long factorial(long long n);

int main()
{   
    int T = 0; cin >> T;
    set<int> s;

    for (int i = 0; i < T; i++) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }

    int a = *s.begin();
    int b = *s.rbegin();
    cout << a * b;

    return 0;
}
