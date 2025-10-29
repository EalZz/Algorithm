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
		int N; cin >> N;

		vector<bool> isView(10, false);

		int mul = 0, ans = 0, cnt = 0;
		while (1) {
			mul += N;
			string str = to_string(mul);
			for (int i = 0; i < str.size(); i++) {
				if (isView[str[i] - '0']) continue;
				isView[str[i] - '0'] = true;
				cnt++;
			}
			if (cnt == 10) break;
		}

		cout << "#" << t << ' ' <<  mul <<  '\n';
	}

	return 0;
}