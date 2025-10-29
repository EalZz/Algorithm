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
			switch (c) {
			case 'I' :
				int x, y, z; cin >> x >> y;
				vector<int> tmp(cord.begin() + x, cord.end());
				cord.erase(cord.begin() + x, cord.end());

				while (y--) {
					int s; cin >> s;
					cord.push_back(s);
				}
				cord.insert(cord.end(), tmp.begin(), tmp.end());
			}
		}

		cout << "#" << t << ' ';
		for (int i = 0; i < 10; i++) cout << cord[i] << ' ';
		cout << '\n';
	}

	return 0;
}