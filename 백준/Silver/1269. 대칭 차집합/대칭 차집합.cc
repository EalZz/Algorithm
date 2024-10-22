#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n = 0, m = 0;
    int tmp1, tmp2;
    vector<int> a, b;
    vector<int> index;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> tmp1;
        a.push_back(tmp1);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++) {
        cin >> tmp2;
        b.push_back(tmp2);
    }
    sort(b.begin(), b.end());

    int count = 0;
    for (int i = 0; i < m; i++) {
        if (binary_search(a.begin(), a.end(), b[i])) {
            count++;
        }
    }

    cout << m + n - 2 * count << "\n";

    return 0;
}