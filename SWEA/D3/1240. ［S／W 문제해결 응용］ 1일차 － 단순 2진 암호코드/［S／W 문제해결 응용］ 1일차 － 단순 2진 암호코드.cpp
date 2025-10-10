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

	vector<string> codes = {
		"0001101", "0011001", "0010011", "0111101", "0100011",
		"0110001", "0101111", "0111011", "0110111", "0001011"
	};

	for (int t = 1; t <= T; t++) {
		int N, M; cin >> N >> M;

		string tmp;
		vector<vector<int>> v(N, vector<int>(M));
		int startrow = -1;
		vector<int> code(56, 0);
		for (int row = 0; row < N; row++) {
			cin >> tmp;
			for (int col = 0; col < M; col++) {
				v[row][col] = tmp[col] - '0';
				if (startrow == -1 && v[row][col] == 1) startrow = row;
			}
		}

		int endcol = -1;
		for (int i = v[startrow].size() - 1; i >= 0; i--) {
			if (v[startrow][i] == 1) {
				endcol = i;
				break;
			}
		}

		tmp.clear();
		int decoding = 0, sum = 0, count = 1;
		for (int i = endcol - 55; i <= endcol; i++) {
			if (tmp.size() == 7) {
				for (int j = 0; j < codes.size(); j++) {
					if (tmp == codes[j]) {
						sum += j;
						decoding += ((count % 2) ? j * 3 : j);

						count++;
						tmp.clear();
						break;
					}
				}
			}
			tmp.push_back(v[startrow][i] + '0');
		}
		for (int j = 0; j < codes.size(); j++) {
			if (tmp == codes[j]) {
				sum += j;
				decoding += j;
				tmp.clear();
				break;
			}
		}

		int result = (decoding % 10) ? 0 : sum;
		cout << "#" << t << ' ' << result << '\n';
	}

	return 0;
}