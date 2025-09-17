#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <memory>

using namespace std;
//int cnt = 0, cnt1 = 0;
int memo[21][21][21];
//int memo[10000001];
string change;

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a; cin >> a; 
		//int b; cin >> b;
		//vector<vector<int>>v(9, vector<int>(9));

		cout << "#" << t << '\n';

		cout << a / 50000 << ' ';
		a %= 50000;
		cout << a / 10000 << ' ';
		a %= 10000;
		cout << a / 5000 << ' ';
		a %= 5000;
		cout << a / 1000 << ' ';
		a %= 1000;
		cout << a / 500 << ' ';
		a %= 500;
		cout << a / 100 << ' ';
		a %= 100;
		cout << a / 50 << ' ';
		a %= 50;
		cout << a / 10 << '\n';
	}

	return 0;
}