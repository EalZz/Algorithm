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
int cnt = 0, cnt1 = 0;
int memo[21][21][21];
//int memo[10000001];
string change;

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a, b; cin >> a >> b;

		int mul = (a > 9 || b > 9) ? -1 : a * b;

		cout << "#" << t << ' ';
		cout << mul << '\n';
	}

	return 0;
}