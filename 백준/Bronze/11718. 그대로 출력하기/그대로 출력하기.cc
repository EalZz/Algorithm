#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string str;

	while (1) {
		getline(cin, str);
		if (str == "")
			break;
		cout << str << endl;
	}
}