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
		int a; cin >> a;
		//int b; cin >> b;
		vector<vector<int>>v(a, vector<int>(a));

		cout << "#" << t << '\n';
		for (int row = 0; row < a; row++) {
			for (int col = 0; col < row + 1; col++) {
				if (col == 0 || col == row) {
					v[row][col] = 1;
					cout << v[row][col] << ' ';
					continue;
				}

				v[row][col] = v[row - 1][col - 1] + v[row - 1][col];
				cout << v[row][col] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}