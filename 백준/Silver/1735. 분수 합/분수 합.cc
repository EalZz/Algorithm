#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;

    int x = a * d + b * c, y = b * d;
    
    int x1 = x, y1 = y, z = 0;

    while (y1) {
        z = x1 % y1;
        x1 = y1;
        y1 = z;
    }

    cout << x / x1 << " " << y / x1;

    return 0;
}