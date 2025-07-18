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
    int K = 0; cin >> K;
    cout << factorial(N) / (factorial(K) * factorial(N - K));
    return 0;
}

int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}