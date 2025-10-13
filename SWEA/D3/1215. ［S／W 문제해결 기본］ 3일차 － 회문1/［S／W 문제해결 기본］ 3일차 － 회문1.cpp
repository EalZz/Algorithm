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
		int test, result = 0; cin >> test;

		if (test == 1) {
			cout << "#" << t << ' ' << 64 << '\n';
			continue;
		}

		vector<string> v(8),v2(8, string(8, ' '));
		for (int i = 0; i < 8; i++) {
			cin >> v[i];
			for (int j = 0; j < 8; j++) v2[j][i] = v[i][j];
		}

		for (int row = 0; row < 8; row++) {
			for (int col = 0; col < 9 - test; col++) {
				string tmp1 = v[row].substr(col, test);
				string tmp2 = tmp1;
				reverse(tmp2.begin(), tmp2.end());


				string tmp3 = v2[row].substr(col, test);
				string tmp4 = tmp3;
				reverse(tmp4.begin(), tmp4.end());

				if (tmp1 == tmp2) result++;
				if (tmp3 == tmp4) result++;
			}
		}

		cout << "#" << t << ' ' << result << '\n';
	}

	return 0;
}