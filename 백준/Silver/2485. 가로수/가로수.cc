#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
using namespace std;
long long gcd(long long a, long long b);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<long long int> a, diff;
    int n = 0;
    cin >> n;
    long long int cnt = 0;
    long long int min = 100000000;

    while (n--) {
        long long int tmp = 0;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());

    for (int i = 1; i < a.size(); i++) {
        diff.push_back(a[i] - a[i - 1]);
    }

    long long int diff_gcd = diff[0];
    for(int i = 1; i < diff.size(); i++) {
        diff_gcd = gcd(diff_gcd, diff[i]);
    }

    cnt = (a[a.size() - 1] - a[0]) / diff_gcd + 1;
    
    cout << cnt - a.size();

    return 0;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}