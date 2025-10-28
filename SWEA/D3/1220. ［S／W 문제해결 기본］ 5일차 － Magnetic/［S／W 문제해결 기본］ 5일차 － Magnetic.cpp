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
	int T = 10; //cin >> T;

	for (int t = 1; t <= T; t++) {
		int test; cin >> test;

		vector<vector<int>> v(100, vector<int>(100));
		vector<pair<int, int>>  N, S;
		for (int row = 0; row < 100; row++) {
			for (int col = 0; col < 100; col++) {
				cin >> v[row][col];
				if (v[row][col] == 1) N.push_back({ row, col });
			}
		}

		int cnt = 0;
		for (auto& p : N) {
			int Nrow = p.first;
			int Ncol = p.second;

			Nrow++;
			while (Nrow < 100) {
				if (v[Nrow][Ncol] == 2) {
					cnt++;
					break;
				}
				if (v[Nrow][Ncol] == 1) break;
				Nrow++;
			}
		}

		cout << "#" << t << ' ' << cnt << '\n';
	}

	return 0;
}