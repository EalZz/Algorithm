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

void nQueen(int N, int row, vector<bool>& bcol, vector<bool>& bdiag1, vector<bool>& bdiag2);
int cnt = 0;

int main() {
	int T = 0; cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;
		cnt = 0;
		int N; cin >> N;

		vector<bool> bcol(N, false);
		vector<bool> bdiag1(N * 2 - 1, false);
		vector<bool> bdiag2(N * 2 - 1, false);

		nQueen(N, 0, bcol, bdiag1, bdiag2);

		cout << "#" << t << ' ' << cnt << '\n';
	}

	return 0;
}

void nQueen(int N, int row, vector<bool>& bcol, vector<bool>& bdiag1, vector<bool>& bdiag2) {
	if (row == N) {
		cnt++;
		return;
	}

	for (int col = 0; col < N; col++) {
		if (bcol[col] || bdiag1[row - col + N - 1] || bdiag2[row + col]) continue;

		bcol[col] = true;
		bdiag1[row - col + N - 1] = true;
		bdiag2[row + col] = true;

		nQueen(N, row + 1, bcol, bdiag1, bdiag2);

		bcol[col] = false;
		bdiag1[row - col + N - 1] = false;
		bdiag2[row + col] = false;
	}
	return;
}