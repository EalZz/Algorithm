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

		int N; cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) cin >> v[i];
		sort(v.begin(), v.end());

		cout << "#" << t << ' ';
		for (auto& i : v) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}