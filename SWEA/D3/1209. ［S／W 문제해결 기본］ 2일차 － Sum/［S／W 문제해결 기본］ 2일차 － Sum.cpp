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
		vector<int> sumRow(100), sumCol(100);
		for (int row = 0; row < 100; row++) {
			for (int col = 0; col < 100; col++) {
				int tmp; cin >> tmp;
				sumRow[col] += tmp;
				sumCol[row] += tmp;
				if (row == col) sumDiag1 += tmp;
				if (row + col == 99) sumDiag2 += tmp;
			}
		}
		sort(sumRow.begin(), sumRow.end());
		sort(sumCol.begin(), sumCol.end());
		long long maxRow = sumRow.back(), maxCol = sumCol.back();
		sumMax = max(maxRow, max(maxCol, max(sumDiag1, sumDiag2)));

		cout << "#" << t;
		cout << ' ' << sumMax << '\n';
	}

	return 0;
}