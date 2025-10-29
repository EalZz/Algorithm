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

		vector<int> tmp1(N), tmp2(M), A, B;
		for (int i = 0; i < N; i++) cin >> tmp1[i];
		for (int i = 0; i < M; i++) cin >> tmp2[i];
		if (N > M) {
			A = tmp1;
			B = tmp2;
		}
		else {
			A = tmp2;
			B = tmp1;
		}

		int ans = 0;
		for (int i = 0; i < A.size() - B.size() + 1; i++) {
			int tmp = 0;
			for (int idx = i; idx < i + B.size(); idx++) tmp += A[idx] * B[idx - i];
			ans = max(ans, tmp);
		}

		cout << "#" << t << ' ' << ans << '\n';
	}

	return 0;
}