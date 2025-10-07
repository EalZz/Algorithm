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
	//int T; cin >> T;

	for (int t = 1; t <= 10; t++) {
		int asdf; cin >> asdf;
		
		long long sumDiag1 = 0, sumDiag2 = 0, sumMax = 0;
		vector<long long> sumRow(100, 0), sumCol(100, 0);
		for (int row = 0; row < 100; row++) {
			for (int col = 0; col < 100; col++) {
				int tmp; cin >> tmp;
				sumRow[row] += tmp;
				sumCol[col] += tmp;
				if (row == col) sumDiag1 += tmp;
				if (row + col == 99) sumDiag2 += tmp;
			}
		}
		long long maxRow = 0, maxCol = 0;
		for (int i = 0; i < 100; i++) {
			maxRow = max(maxRow, sumRow[i]);
			maxCol = max(maxCol, sumCol[i]);
		}
		sumMax = max(maxRow, max(maxCol, max(sumDiag1, sumDiag2)));

		cout << "#" << t;
		cout << ' ' << sumMax << '\n';
	}

	return 0;
}