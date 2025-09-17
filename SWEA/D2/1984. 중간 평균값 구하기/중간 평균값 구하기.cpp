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
		//int a; cin >> a;
		//int b; cin >> b;
		//int c; cin >> c;
		vector<int> v(10);
		for (int i = 0; i < 10; i++) cin >> v[i];

		sort(v.begin(), v.end());
		
		int avg = 0;
		for (int i = 1; i < 9; i++) avg += v[i];
		
		cout << "#" << t << ' ';
		cout << (avg + 4) / 8 << '\n';
	}

	return 0;
}