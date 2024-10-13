#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	int sqr[3][2];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> sqr[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		if (sqr[0][i] == sqr[1][i])
			cout << sqr[2][i];
		else if (sqr[0][i] == sqr[2][i])
			cout << sqr[1][i];
		else if (sqr[1][i] == sqr[2][i])
			cout << sqr[0][i];

		cout << " ";
	}

	return 0;
}