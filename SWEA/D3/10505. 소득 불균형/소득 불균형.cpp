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
		vector<int> v(a);

		int avg = 0;
		for (int i = 0; i < a; i++) {
			cin >> v[i];
			avg += v[i];
		}

		avg /= a;

		int cnt = 0;
		for (auto s : v) {
			if (s <= avg) cnt++;
		}

		cout << "#" << t << ' ';
		cout << cnt++ << '\n';
	}

	return 0;
}