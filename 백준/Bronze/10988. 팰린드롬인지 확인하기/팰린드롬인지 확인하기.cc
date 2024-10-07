#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	//int n = 0;
	//cin >> n;
	//char* ch = new char[n];

	string str;
	cin >> str;
	int length = str.length();
	int count = 0;

	for (int i = 0; i < length / 2; i++) {
		if (str[i] != str[length - 1 - i]) {
			count += 1;
			if (count > 0) {
				cout << 0 << endl;
				break;
			}
		}
	}
	if (count == 0)
		cout << 1 << endl;


	return 0;
}