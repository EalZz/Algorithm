#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int* arr1 = new int[n];
	int* arr2 = new int[n];

	if (n == 1) {
		cin >> arr1[0] >> arr2[0];
		cout << 0;
	}
	else {
		int min1 = INT_MAX, max1 = INT_MIN,
			min2 = INT_MAX, max2 = INT_MIN;
		for (int i = 0; i < n; i++) {
			cin >> arr1[i] >> arr2[i];
			if (max1 < arr1[i])
				max1 = arr1[i];
			if (max2 < arr2[i])
				max2 = arr2[i];

			if (min1 > arr1[i])
				min1 = arr1[i];
			if (min2 > arr2[i])
				min2 = arr2[i];
		}

		cout << (max1 - min1) * (max2 - min2);
	}

	return 0;
}