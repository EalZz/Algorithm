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
int memo[21][21][21];
//int memo[10000001];
string change;

int main() {
	int T = 1; //cin >> T;

	for (int t = 1; t <= T; t++) {
		int a; cin >> a; 
		//int b; cin >> b;
		//vector<vector<int>>v(9, vector<int>(9));
		for (int i = 1; i <= a; i++) {
			string tmp = to_string(i);
			bool isClap = false;
			int cnt = 0;
			for (auto c : tmp) {
				if (c == '3' || c == '6' || c == '9') {
					cnt++;
					isClap = true;
				}
			}
			if (!isClap) cout << i;
			else {
				while (cnt--) cout << '-';
			}
			cout << ' ';
		}

		//cout << "#" << t << ' ';

	}

	return 0;
}