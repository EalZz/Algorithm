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

		int dist = 0, speed = 0;
		while (N--) {
			int cmd; cin >> cmd;
			switch (cmd) {
			case 0 : break;
			case 1 :
				int paccel; cin >> paccel;
				speed += paccel;
				break;
			case 2:
				int maccel; cin >> maccel;
				speed -= maccel;
				if (speed < 0) speed = 0;
				break;
			}
			dist += speed;
		}

		cout << "#" << t << ' ' << dist;
		cout << '\n';
	}

	return 0;
}