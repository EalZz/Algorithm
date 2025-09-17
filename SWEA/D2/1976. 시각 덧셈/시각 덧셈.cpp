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

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		int a; cin >> a; int a1; cin >> a1;
		int b; cin >> b; int b1; cin >> b1;
		//vector<vector<int>>v(9, vector<int>(9));

		int hour = a + b;
		int minute = a1 + b1;
		if (minute >= 60) {
			hour += 1;
			minute -= 60;
		}
		if (hour > 12) hour -= 12;

		cout << "#" << t << ' ';
		cout << hour << ' ' << minute << '\n';
	}

	return 0;
}