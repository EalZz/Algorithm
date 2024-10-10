#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int invalue = 0;
	cin >> invalue;
	//int* arr = new int[n];
	int result = 1;
	int n = 1;

	while (invalue > result) {
		result += n * 6;
		n++;
	}
	cout << n;

	return 0;
}

