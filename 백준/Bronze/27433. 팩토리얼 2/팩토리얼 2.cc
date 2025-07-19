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
long long factorial(long long t);

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T = 0; cin >> T;
    
    cout << factorial(T);

    return 0;
}

long long factorial(long long t) {
    if (t == 0) return 1;
    long long n = t * factorial(t - 1);
    return n;
}