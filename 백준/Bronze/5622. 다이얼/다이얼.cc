#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str[8];
	str[0] = "ABC";
	str[1] = "DEF";
	str[2] = "GHI";
	str[3] = "JKL";
	str[4] = "MNO";
	str[5] = "PQRS";
	str[6] = "TUV";
	str[7] = "WXYZ";
	string num;
	cin >> num;
	int* numind = new int[num.length()];
	int sum = num.length() * 3;

	for (int i = 0; i < num.length(); i++) {
		for (int j = 0; j < 8; j++) {
			if (str[j].find(num[i]) != string::npos) {
				numind[i] = j;
			}
		}
		sum += numind[i];
	}
	
	cout << sum << endl;
}