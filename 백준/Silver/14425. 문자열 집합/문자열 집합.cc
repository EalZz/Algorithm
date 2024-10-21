#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n = 0, m = 0, count = 0;
    vector<string> a(n);
    string str, check;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str;
        a.push_back(str);
    }
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++) {
        cin >> check;
        if (binary_search(a.begin(), a.end(), check))
            count++;
    }
    cout << count << endl;

	return 0;
}
