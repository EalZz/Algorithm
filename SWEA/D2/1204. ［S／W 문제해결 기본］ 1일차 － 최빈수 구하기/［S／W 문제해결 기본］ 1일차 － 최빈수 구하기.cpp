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
		vector<vector<int>> v(101, vector<int>(2, -1));
		//int b; cin >> b;
		//int c; cin >> c;
		for (int i = 0; i < 1000; i++) {
			int tmp; cin >> tmp;
			if(v[tmp][0] == -1) v[tmp][0] = tmp;
			v[tmp][1] += 1;
		}

		sort(v.begin(), v.end(), [](vector<int> a, vector<int> b) {
			if (a[1] == b[1]) return a[0] > b[0];
			return a[1] > b[1];
			});

		cout << "#" << t << ' ';
		cout << v[0][0] << '\n';
	}

	return 0;
}