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
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a; cin >> a;
		vector<vector<int>> v(a, vector<int>(a, 0));
		v[0][0] = 1;

		int dy[4] = { 0, 1, 0, -1 };
		int dx[4] = { 1, 0, -1, 0 };

		int num = 2, row = 0, col = 0, idx = 0;

		while (num <= a * a) {
			row += dy[idx];
			col += dx[idx];

			if (row < 0 || col < 0 || row >= a || col >= a || v[row][col] != 0) {
				row -= dy[idx];
				col -= dx[idx];
				if (idx < 3) idx++;
				else idx = 0;
				continue;
			}

			v[row][col] = num;
			num++;
		}

		cout << "#" << t << '\n';
		for (auto& n : v) {
			for (auto& m : n) cout << m << ' ';
			cout << '\n';
		}
	}

	return 0;
}