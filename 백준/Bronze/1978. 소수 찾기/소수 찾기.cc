#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	int a = 0, count = 0;
	cin >> a;
	int* arr = new int[a];

	for (int i = 0; i < a; i++) {
		int test = 0;
		cin >> test;

		bool check = true;
		if (test == 1) {
			check = false;
		}
		else if (test == 2) {
			check = true;
		}
		else {
			for (int i = 2; i < test; i++) {
				if (test % i == 0) {
					check = false;
					break;
				}
			}
		}

		if (check == true) {
			count++;
		}
	}
	cout << count << endl;

	return 0;
}