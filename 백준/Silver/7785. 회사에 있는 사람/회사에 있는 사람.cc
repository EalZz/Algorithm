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

    int n = 0;
    map<string, string, greater<string>> a;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;
        a[name] = state;
    }

    map<string, string>::iterator iter;
    for (iter = a.begin(); iter != a.end(); iter++) {
        if (iter->second == "enter") {
            cout << iter->first << "\n";
        }
    }

	return 0;
}