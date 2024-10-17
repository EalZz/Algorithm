#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int count = 0;

	while (n) {
		if (n % 5 == 0) {
			count += n / 5;
			n = 0;
			break;
		}
		n -= 3;
		count++;

		if (n < 0) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << count << endl;

	return 0;
}

