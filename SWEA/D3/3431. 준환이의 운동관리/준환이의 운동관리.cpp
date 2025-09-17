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
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;

		int time = (a > c) ? a - c : (b < c) ? -1 : 0;

		cout << "#" << t << ' ';
		cout << time << '\n';
	}

	return 0;
}