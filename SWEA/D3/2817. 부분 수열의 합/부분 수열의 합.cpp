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

void dfs(int K, int idx, int sum, vector<int>& v);
int cnt = 0;

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;
		int N, K; cin >> N >> K;
		vector<int> v(N);
		for (int i = 0; i < N; i++) cin >> v[i];

		cnt = 0;
		dfs(K, 0, 0, v);
		if (K == 0) cnt--;

		cout << "#" << t << ' ' << cnt << ' ';
		cout << '\n';
	}

	return 0;
}

void dfs(int K, int idx, int sum, vector<int>& v) {
	if (idx == v.size()) return;

	dfs(K, idx + 1, sum, v);
	sum += v[idx];
	dfs(K, idx + 1, sum, v);
	
	if (sum == K) cnt++;

	return;
}