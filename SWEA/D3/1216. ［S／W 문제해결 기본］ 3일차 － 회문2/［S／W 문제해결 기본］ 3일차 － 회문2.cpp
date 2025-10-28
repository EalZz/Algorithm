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
bool dp[101][101];
int cnt = 0;

void isPelin(string& s, int start, int end);

int main() {
	int T = 10; //cin >> T;

	for (int t = 1; t <= T; t++) {
		int test; cin >> test;

		cnt = 0;

		vector<string> v1(100), v2(100);
		for (int i = 0; i < 100; i++) {
			cin >> v1[i];
			for (int j = 0; j < 100; j++) v2[j].push_back(v1[i][j]);
		}

		for (int row = 0; row < 100; row++) {
			for (int i = 0; i < 101; i++) fill(dp[i], dp[i] + 101, false);
			for (int len = 1; len <= 100; len++) {
				for (int start = 0; start + len - 1 < 100; start++) {
					int end = start + len - 1;
					isPelin(v1[row], start, end);
				}
			}
		}

		for (int row = 0; row < 100; row++) {
			for (int i = 0; i < 101; i++) fill(dp[i], dp[i] + 101, false);
			for (int len = 1; len <= 100; len++) {
				for (int start = 0; start + len - 1 < 100; start++) {
					int end = start + len - 1;
					isPelin(v2[row], start, end);
				}
			}
		}

		cout << "#" << test << ' ' << cnt << '\n';
	}

	return 0;
}

void isPelin(string& s, int start, int end) {
	if (start == end) dp[start][end] = true;
	else if (end - start == 1 && s[start] == s[end]) dp[start][end] = true;
	else if (s[start] == s[end] && dp[start + 1][end - 1]) dp[start][end] = true;

	if(dp[start][end] == true) cnt = max(cnt, end - start + 1);

	return;
}