#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {
    int a = n, b = m;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    
    int gcd = a;
    int lcm = (n * m) / gcd;

    return {gcd, lcm};
}