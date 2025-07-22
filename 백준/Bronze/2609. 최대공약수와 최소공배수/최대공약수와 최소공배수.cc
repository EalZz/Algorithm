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
int gcd(int T, int M);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0, M = 0; 
    cin >> T >> M;
    
    int g = gcd(T, M);

    cout << g << '\n' << T * M / g;

    return 0;
}

int gcd(int T, int M) {
    if (T % M == 0) return M;
    int g = T % M;
    return gcd(M, g);
}