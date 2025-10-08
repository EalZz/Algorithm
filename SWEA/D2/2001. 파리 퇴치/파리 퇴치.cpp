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
		int a, b; cin >> a >> b;
		vector<vector<int>> v(a, vector<int>(a));

		for (int row = 0; row < a; row++) {
			for (int col = 0; col < a; col++) cin >> v[row][col];
		}

		int sumMax = 0;
		for (int rows = 0; rows < a - b + 1; rows++) {
			for (int cols = 0; cols < a - b + 1; cols++) {
				int sum = 0;
				for (int row = rows; row < rows + b; row++) {
					for (int col = cols; col < cols + b; col++) sum += v[row][col];
				}
				sumMax = max(sumMax, sum);
			}
		}

		cout << "#" << t << ' ' << sumMax << '\n';
	}

	return 0;
}