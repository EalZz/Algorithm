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
		vector<vector<int>> v(a, vector<int>(a));

		string tmp; 
		for (int row = 0; row < a; row++) {
			cin >> tmp;
			for (int col = 0; col < a; col++) v[row][col] = tmp[col] - '0';
		}

		int sum = 0, center = a / 2;
		int sidx = center, count = 1;
		for (int row = 0; row < center; row++) {
			int idx = sidx;
			for (int i = 0; i < count; i++) {
				sum += v[row][idx];
				idx++;
			}
			sidx--;
			count += 2;
		}
		for (int row = center; row < a; row++) {
			int idx = sidx;
			for (int i = 0; i < count; i++) {
				sum += v[row][idx];
				idx++;
			}
			sidx++;
			count -= 2;
		}

		cout << "#" << t << ' ' << sum << '\n';
	}

	return 0;
}