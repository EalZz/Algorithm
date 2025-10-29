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

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;

		int P, Q, R, S, W; 
		cin >> P >> Q >> R >> S >> W;
		
		int ans = 0;
		if (W <= R) ans = min(P * W, Q);
		else ans = min(P * W, Q + (W - R) * S);

		cout << "#" << t << ' ' << ans;
		cout << '\n';
	}

	return 0;
}