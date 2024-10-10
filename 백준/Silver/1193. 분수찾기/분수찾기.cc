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

	while (invalue >= result) {
		result = result + n;
		n++;
	}
	int sub = result - invalue;

	if (n % 2 == 1) {
		cout << n - sub << "/" << sub;
	}
	else {
		cout << sub << "/" << n - sub;

	}

	return 0;
}


