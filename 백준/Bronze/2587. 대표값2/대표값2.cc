#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	//int n = 0;
	//cin >> n;
	int* arr = new int[5];
	int key = 0;
	int index = 0;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	for (int i = 1; i < 5; i++) {
		key = arr[i];
		index = i;
		for (int j = i - 1; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
			index = j;
		}
		arr[index] = key;
	}

	cout <<  sum / 5 << endl
		<< arr[2] << endl;

	delete arr;

	return 0;
}

