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

int main() {
	int T = 10; //cin >> T;

	for (int t = 1; t <= T; t++) {
		//int tc; cin >> tc;

		vector<int> cord;
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			int tmp; cin >> tmp;
			cord.push_back(tmp);
		}

		cin >> N;
		while (N--) {
			char c; cin >> c;
			vector<int> tmp;
			switch (c) {
				int x, y;
			case 'I':
				cin >> x >> y;
				for (int i = 0; i < y; i++) {
					int s; cin >> s;
					tmp.push_back(s);
				}
				cord.insert(cord.begin() + x, tmp.begin(), tmp.end());
				break;
			case 'D':
				cin >> x >> y;
				cord.erase(cord.begin() + x, cord.begin() + x + y);
				break;
			case 'A':
				cin >> y;
				while (y--) {
					int s; cin >> s;
					cord.push_back(s);
				}
				break;
			}
		}

		cout << "#" << t << ' ';
		for (int i = 0; i < 10; i++) cout << cord[i] << ' ';
		cout << '\n';
	}

	return 0;
}