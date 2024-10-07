#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int chess[6] = { 1, 1, 2, 2, 2, 8 };
	//long int n = 0;
	//cin >> n;
	//int* arr = new int[n];
	int arr[6] = { 0, };

	for (int i = 0; i < 6; i++) {
		int insert;
		cin >> insert;

		arr[i] = chess[i] - insert;
		cout << arr[i] << " ";
	}

	return 0;
}