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
//int cnt = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[10000001];

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a; cin >> a;
		
		vector<int> v(a);
		for (int i = 0; i < a; i++) cin >> v[i];

		long long gain = 0;
		int MaxP = 0;
		for (int i = a - 1; i >= 0; i--) {
			if (MaxP < v[i]) MaxP = v[i];
			else gain += (MaxP - v[i]);
		}

		cout << "#" << t;
		cout << ' ' << gain << '\n';
	}

	return 0;
}