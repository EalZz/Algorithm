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
		int classmate, num;
		cin >> classmate >> num;
		vector<pair<int, double>> v;
		string grade[10] = { "A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0" };

		for (int i = 1; i <= classmate; i++) {
			double a; cin >> a;
			double b; cin >> b;
			double c; cin >> c;
			double score = a * 0.35 + b * 0.45 + c * 0.2;

			v.push_back({ i, score });
		}
		sort(v.begin(), v.end(), [](pair<int, double> a, pair<int, double> b) {
			return a.second > b.second;
			});

		int idx = -1;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first == num) {
				idx = i;
				break;
			}
		}

		cout << "#" << t << ' ';
		cout << grade[idx / (classmate / 10)] << '\n';
	}

	return 0;
}