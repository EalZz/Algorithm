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

int dfs(int node, vector<vector<int>>& edge, vector<bool>& isVisited);

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int N = 0, M = 0;
		cin >> N >> M;

		vector<vector<int>> edge(N + 1);
		for (int i = 0; i < M; i++) {
			int x = 0, y = 0;
			cin >> x >> y;
			edge[x].push_back(y); 
			edge[y].push_back(x);
		}

		int maxValue = 0;
		for (int i = 1; i <= N; i++) {
			vector<bool> isVisited(N + 1, false);
			maxValue = max(maxValue, dfs(i, edge, isVisited));
		}


		cout << "#" << t << ' ' << maxValue << '\n';
	}

	return 0;
}

int dfs(int node, vector<vector<int>>& edge, vector<bool>& isVisited) {
	isVisited[node] = true;
	int depth = 1;

	for (auto e : edge[node]) {
		if (!isVisited[e]) depth = max(depth, 1 + dfs(e, edge, isVisited));
	}

	isVisited[node] = false;
	return depth;
}