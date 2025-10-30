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

using namespace std;

map<int, int> days = {
	{1, 31}, {2,28}, {3, 31}, {4, 30}, {5, 31}, {6, 30},
	{7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
};

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;

		int m1, d1, m2, d2;
		cin >> m1 >> d1 >> m2 >> d2;

		int ans = 1;
		if (m1 == m2) ans += (d2 - d1);
		else {
			ans += (days[m1] - d1);
			for (int i = m1 + 1; i < m2; i++) ans += days[i];
			ans += d2;
		}

		cout << "#" << t << ' ' << ans;
		cout << '\n';
	}

	return 0;
}