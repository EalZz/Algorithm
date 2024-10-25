#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	

	for (int i = 0; i < n; i++) {
		int a = i, sum = i;
		while (a != 0) {
			sum += a % 10;
			a /= 10;
		}
		if (n == sum) {
			cout << i << endl;
			return 0;
		}
	}

	cout << 0 << endl;
	return 0;
}