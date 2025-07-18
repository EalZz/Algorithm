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
int factorial(int n);

int main()
{   
    int N = 0; cin >> N;
    cout << factorial(N);
    return 0;
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}