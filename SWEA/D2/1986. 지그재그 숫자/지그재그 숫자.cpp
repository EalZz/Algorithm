#include<iostream>

using namespace std;

int main(int argc, char** argv){
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case) {
		cout << "#" << test_case << " ";
		int a = 0, sum = 0;
        cin >> a;
        sum = (a % 2 == 0) ? a / 2 * -1 : (a + 1) / 2;
        cout << sum << endl;
	}
	return 0;
}