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
		int N, K, result = 0; cin >> N >> K;
		vector<vector<int>> v(N, vector<int>(N));

		for (int row = 0; row < N; row++) {
			int cnt = 0;
			for (int col = 0; col < N; col++) {
				cin >> v[row][col];
				if (v[row][col] == 1) cnt++;
				else {
					if (cnt == K) result++;
					cnt = 0;
				}
			}
			if (cnt == K) result++;
			cnt = 0;
		}

		for (int col = 0; col < N; col++) {
			int cnt = 0;
			for (int row = 0; row < N; row++) {
				if (v[row][col] == 1) cnt++;
				else {
					if (cnt == K) result++;
					cnt = 0;
				}
			}
			if (cnt == K) result++;
			cnt = 0;
		}

        cout << "#" << t << ' ' << result << '\n';
	}

	return 0;
}