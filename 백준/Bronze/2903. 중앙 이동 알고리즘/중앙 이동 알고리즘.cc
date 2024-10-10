#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	//int* arr = new int[n];
	int addition = pow(2, (n - 1));
	int result = pow((1 + 2 * addition), 2);

	cout << result;

	return 0;
}
