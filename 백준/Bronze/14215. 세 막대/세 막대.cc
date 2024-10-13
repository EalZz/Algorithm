#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int main() {
	int tri[3];
	int max = 0, index = 0, sum = 0;

	for (int i = 0; i < 3; i++) {
		cin >> tri[i];
		if (max < tri[i]) {
			max = tri[i];
			index = i;
		}
	}
	for (int i = 0; i < 3; i++) {
		if (index != i) {
			sum += tri[i];
		}
	}

	if (sum <= max) {
		while (max - sum + 1) {
			max--;
		}
	}

	cout << sum + max;


	return 0;
}