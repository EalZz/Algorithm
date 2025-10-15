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
	int T = 10;// cin >> T;

	for (int t = 1; t <= T; t++) {
		int test, result = 0; cin >> test;

		string str, token;
		cin >> token >> str;

		for (int i = 0; i < str.size() - token.size() + 1; i++) {
			if (token[0] != str[i]) continue;

			bool match = true;
			for (int j = 0; j < token.size(); j++) {
				if (str[i + j] != token[j]) {
					match = false;
					break;
				}
			}
			if (match) result++;;
		}

		cout << "#" << t << ' ' << result << '\n';
	}

	return 0;
}