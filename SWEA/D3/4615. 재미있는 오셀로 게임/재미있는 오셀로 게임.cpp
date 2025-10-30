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

using namespace std;

int dy[8] = { 1, -1 , 0, 0, 1, 1, -1, -1 };
int dx[8] = { 0, 0 , 1, -1, 1, -1, 1, -1 };

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;
		int N, M; cin >> N >> M;
		vector<vector<int>> v(N, vector<int>(N, 0));

		v[N / 2 - 1][N / 2 - 1] = 2; 
		v[N / 2 - 1][N / 2] = 1;
		v[N / 2][N / 2 - 1] = 1;
		v[N / 2][N / 2] = 2;

		while (M--) {
			int row, col, color, rcolor;
			cin >> row >> col >> color;
			row--; col--;
			if (color == 1) rcolor = 2;
			else rcolor = 1;

			v[row][col] = color;

			for (int i = 0; i < 8; i++) {
				int nrow = row + dy[i];
				int ncol = col + dx[i];

				if (nrow >= N || ncol >= N || nrow < 0 || ncol < 0 || v[nrow][ncol] != rcolor) continue;

				vector<pair<int, int>> pv;
				pv.push_back({ nrow, ncol });
				bool isAble = true;
				while (1) {
					nrow += dy[i];
					ncol += dx[i];

					if (nrow >= N || ncol >= N || nrow < 0 || ncol < 0 || v[nrow][ncol] == 0) {
						isAble = false;
						break;
					}
					if (v[nrow][ncol] == color) break;
					if (v[nrow][ncol] == rcolor) pv.push_back({ nrow, ncol });
				}
				if (!isAble) continue;

				for (auto& p : pv) v[p.first][p.second] = color;
			}
		}

		int black = 0, white = 0;
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (v[row][col] == 1) black++;
				if (v[row][col] == 2) white++;
			}
		}

		cout << "#" << t << ' ' << black << ' ' << white;
		cout << '\n';
	}

	return 0;
}
