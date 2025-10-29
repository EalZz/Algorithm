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
		int N, M; cin >> N >> M;
		int dp[10001] = { 0, };

		while (N--) {
			int value, weight; cin >> value >> weight;
			for (int i = M; i >= weight; i--) {
				dp[i] = max(dp[i], dp[i - weight] + value);
			}
		}
		cout << "#" << t << ' ' << dp[M] << '\n';
	}

	return 0;
}