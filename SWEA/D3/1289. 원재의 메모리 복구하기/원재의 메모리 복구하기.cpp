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

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;

		string s; cin >> s;
		int cnt = 0;
		char pre = '0';
		for (auto& c : s) {
			if (c == pre) continue;
			cnt++;
			pre = c;
		}

		cout << "#" << t << ' ' << cnt << '\n';
	}

	return 0;
}