#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	int key = 0;
	int index = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		key = arr[i];
		index = i;
		for (int j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
			index = j;
		}
		arr[index] = key;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}

	return 0;
}

