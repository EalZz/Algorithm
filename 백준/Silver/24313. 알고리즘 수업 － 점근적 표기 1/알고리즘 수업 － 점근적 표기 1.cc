#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int main() {
	int a_1 = 0, a_2 = 0, c = 0, n = 0;
	cin >> a_2 >> a_1 >> c >> n;

	if (a_2 * n + a_1 <= c * n && a_2 <= c)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}
