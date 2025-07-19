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
long long pibo(long long t);

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T = 0; cin >> T;
    
    cout << pibo(T);

    return 0;
}

long long pibo(long long t) {
    if (t == 0) return 0;
    if (t == 1) return 1;
    long long n = pibo(t - 1) + pibo(t - 2);
    return n;
}