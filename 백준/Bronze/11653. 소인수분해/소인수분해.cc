#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
using namespace std;

int main() {
	int x;
	cin >> x;
	
	if (x == 1) {
		return 0;
	}
	else {
		for (int i = 2; i <= x; i++) {
			while (1) {
				if (x % i == 0) {
					cout << i << endl;
					x /= i;
				}
				else break;
			}
		}
	}
	
	return 0;
}