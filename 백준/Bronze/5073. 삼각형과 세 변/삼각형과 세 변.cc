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
	
	while (1) {
		int max = 0, index = 0, sum = 0;
		
		for (int i = 0; i < 3; i++) {
			cin >> tri[i];
			if (max < tri[i]) {
				max = tri[i];
				index = i;
			}
		}
		if (tri[0] + tri[1] + tri[2] == 0)
			break;
		for (int i = 0; i < 3; i++) {
			if (index != i) {
				sum += tri[i];
			}
		}

		if (sum <= max)
			cout << "Invalid" << endl;
		else if (tri[0] == tri[1] && tri[0] == tri[2])
			cout << "Equilateral" << endl;
		else if (tri[0] == tri[1] || tri[0] == tri[2] || tri[1] == tri[2])
			cout << "Isosceles" << endl;
		else
			cout << "Scalene" << endl;
	}
	

	return 0;
}