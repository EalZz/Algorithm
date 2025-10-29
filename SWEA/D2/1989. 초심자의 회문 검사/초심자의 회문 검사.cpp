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
		bool ans = true;
		for (int i = 0; i < s.size() / 2; i++) {
			if (s[i] == s[s.size() - 1 - i]) continue;
			ans = false;
			break;
		}

		cout << "#" << t << ' ' << ans;
		cout << '\n';
	}

	return 0;
}