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
//int memo[21][21][21];
//int memo[10000001];

int main() {
	int T = 10;// cin >> T;

	for (int t = 1; t <= T; t++) {
		int test; cin >> test;

		deque<int> dq;
		for (int i = 0; i < 8; i++) {
			int tmp; cin >> tmp;
			dq.push_back(tmp);
		}

		int subnum = 1;
		while (1) {
			int tmp = (dq.front() - subnum > 0) ? dq.front() - subnum : 0;

			dq.pop_front();
			dq.push_back(tmp);

			if (tmp == 0) break;
			if (subnum == 5) subnum = 1;
			else subnum++;
		}

		cout << "#" << t << ' '; //<< result << '\n';
		for (auto& n : dq) cout << n << ' ';
		cout << '\n';
	}

	return 0;
}
