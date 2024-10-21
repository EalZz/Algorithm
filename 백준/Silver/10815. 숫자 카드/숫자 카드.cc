#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n = 0, tmp1, m = 0, tmp2;
    vector<int> a, b;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp1;
        a.push_back(tmp1);
    }
    sort(a.begin(), a.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> tmp2;
        b.push_back(tmp2);
    }

    for (int i = 0; i < m; i++) {
        cout << binary_search(a.begin(), a.end(), b[i]) << " ";
    }

	return 0;
}
