#include <iostream>

using namespace std;

long long pow(int n, int c);

int main() {
	int T = 10; //cin >> T;

	for (int t = 1; t <= T; t++) {
		int tc; cin >> tc;

		int n, c; cin >> n >> c;

		cout << "#" << tc << ' ' << pow(n, c) << '\n';
	}

	return 0;
}

long long pow(int n, int c) {
	if (c == 1) return n;

	long long half = pow(n, c / 2);

	if (c % 2 == 1) return half * half * n;
	return half * half;
}
