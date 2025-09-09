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

void dfs(int N, int idx, int last_x, int last_y, int dist, vector<int>& start, vector<int>& end, vector<vector<int>>& home, vector<bool>& isVisited);

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		cnt = 1000000;

		int N = 0; cin >> N;
		vector<int> start(2);
		vector<int> end(2);
		vector<vector<int>> home(N, vector<int>(2));
		vector<bool> isVisited(N ,false);

		cin >> start[0] >> start[1] >> end[0] >> end[1];
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < 2; col++) cin >> home[row][col];
		}
		int last_x = start[0];
		int last_y = start[1];

		dfs(N, 0, last_x, last_y, 0, start, end, home, isVisited);

		cout << "#" << t << ' ';
		cout << cnt << '\n';
	}

	return 0;
}

void dfs(int N, int idx, int last_x, int last_y, int dist, vector<int>& start, vector<int>& end, vector<vector<int>>& home, vector<bool>& isVisited) {
	if (idx == N) {
		dist += abs(last_x - end[0]) + abs(last_y - end[1]);
		cnt = min(cnt, dist);
		return;
	}

	if (dist >= cnt) return;

	for (int i = 0; i < home.size(); i++) {
		if (!isVisited[i]) {
			isVisited[i] = true;
			int next_dist = dist + abs(last_x - home[i][0]) + abs(last_y - home[i][1]);

			dfs(N, idx + 1, home[i][0], home[i][1], next_dist, start, end, home,isVisited);

			isVisited[i] = false;
		}
	}
	return;
}