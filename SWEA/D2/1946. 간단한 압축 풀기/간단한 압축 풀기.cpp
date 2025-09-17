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
int memo[21][21][21];
//int memo[10000001];
string change;

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
		double a; cin >> a;
		//double b; cin >> b;
		//double c; cin >> c;
		string tmp = "";
		for (int i = 0; i < a; i++) {
			char c; cin >> c;
			int num; cin >> num;
			for (int j = 0; j < num; j++) tmp.push_back(c);
		}

		int idx = 0;
		cout << "#" << t << '\n';
		for(int i=0; i<tmp.size(); i++) {
			if (idx != 0 && idx % 10 == 0) cout << '\n';
			cout << tmp[idx];
			idx++;
		}
		cout << '\n';
	}

	return 0;
}