#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	unsigned long long n = 0;
	cin >> n;
	if (n == 1) {
		cout << 0 << endl << 2;
	} else {
		cout << n * (n - 1) / 2 << endl << 2;
	}

	return 0;
}