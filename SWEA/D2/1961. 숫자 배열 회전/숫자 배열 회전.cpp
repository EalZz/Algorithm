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

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;
		
		int N; cin >> N;
		vector<vector<int>> v(N, vector<int>(N)), v90(N, vector<int>(N)), v180(N, vector<int>(N)), v270(N, vector<int>(N));
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) cin >> v[row][col];
		}

		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) v90[col][N - 1 - row] = v[row][col];
		}
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) v180[col][N - 1 - row] = v90[row][col];
		}
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) v270[col][N - 1 - row] = v180[row][col];
		}

		cout << "#" << t << '\n';
		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) cout << v90[row][col];
			cout << ' ';
			for (int col = 0; col < N; col++) cout << v180[row][col];
			cout << ' ';
			for (int col = 0; col < N; col++) cout << v270[row][col];
			cout << '\n';
		}
	}

	return 0;
}