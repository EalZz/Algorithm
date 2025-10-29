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
		int tc; cin >> tc;

		string s, pw; cin >> s;
		for (int i = 0; i < tc; i++) {
			if (!pw.empty() && pw.back() == s[i]) pw.pop_back();
			else pw.push_back(s[i]);
		}

		cout << "#" << t << ' ' << pw;
		//for (int i = 0; i < 10; i++) cout << cord[i] << ' ';
		cout << '\n';
	}

	return 0;
}