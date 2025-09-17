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
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a; cin >> a; 
		int b; cin >> b;
		int c; cin >> c;
		//vector<vector<int>>v(9, vector<int>(9));
		int cnt = 0;
		while (a <= c && b <= c) {
			a >= b ? b += a : a += b;
			cnt++;
		}
		cout << cnt << '\n';
		//cout << "#" << t << ' ';
	}

	return 0;
}