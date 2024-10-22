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

    int n = 0;
    cin >> n;

    while (n--) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b;
        int mul = a * b;

        while (b) {
            c = a % b;
            a = b;
            b = c;
        }
        cout << mul / a << "\n";
    }

    return 0;
}