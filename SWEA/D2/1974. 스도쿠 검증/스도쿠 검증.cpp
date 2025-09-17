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
		//int a; cin >> a;
		//int b; cin >> b;
		//vector<vector<int>>v(9, vector<int>(9));
		vector<vector<bool>> brow(9, vector<bool>(10, false));
		vector<vector<bool>> bcol(9, vector<bool>(10, false));
		vector<vector<bool>> bbox(9, vector<bool>(10, false));
		bool isOK = true;

		for (int row = 0; row < 9; row++) {
			for (int col = 0; col < 9; col++) {
				int num; cin >> num;
				int box = (row / 3) * 3 + (col / 3);
				
				if (brow[row][num] || bcol[col][num] || bbox[box][num]) {
					isOK = false;
					//break;
				}
				brow[row][num] = true;
				bcol[col][num] = true;
				bbox[box][num] = true;
			}
			//if (!isOK) break;
		}

		cout << "#" << t << ' ';
		if (isOK) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}