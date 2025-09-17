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
int cnt = 0, cnt1 = 0;
int memo[21][21][21];
//int memo[10000001];
string change;

void dfs(string N, int M, int count, set<pair<string, int>>& pruning);

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		int len = 0; cin >> len;
		int upmax = 0, downmax = 0, tmp = 0;

		cin >> tmp;
		for (int i = 1; i < len; i++) {
			int cur = 0; cin >> cur;

			if (cur >= tmp) upmax = max(upmax, cur - tmp);
			else downmax = max(downmax, tmp - cur);

			tmp = cur;
		}

		cout << "#" << t << ' ';
		cout << upmax << ' ' << downmax << '\n';
	}

	return 0;
}