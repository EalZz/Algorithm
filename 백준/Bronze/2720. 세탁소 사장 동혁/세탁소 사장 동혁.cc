#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n = 0;
	cin >> n;
	int* arr = new int[n];
	int count_q = 0, count_d = 0, count_n = 0, count_p = 0;

	for (int i = 0; i < n; i++){
		count_q = 0, count_d = 0, count_n = 0, count_p = 0;

		int change = 0;
		cin >> change;

		count_q = change / 25;
		change = change % 25;

		count_d = change / 10;
		change = change % 10;

		count_n = change / 5;
		change = change % 5;

		count_p = change;

		cout << count_q << " " << count_d << " " << count_n << " " << count_p << endl;
	}

	return 0;
}
