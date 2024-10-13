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
	int sum = 0;

	for (int i = 0; i < 3; i++) {
		cin >> tri[i];
		sum += tri[i];
	}

	if (sum != 180)
		cout << "Error";
	else if (tri[0] == tri[1] && tri[0] == tri[2])
		cout << "Equilateral";
	else if (tri[0] == tri[1] || tri[0] == tri[2] || tri[1] == tri[2])
		cout << "Isosceles";
	else
		cout << "Scalene";

	return 0;
}