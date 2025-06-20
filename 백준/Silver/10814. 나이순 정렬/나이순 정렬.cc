#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<deque>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<int, pair<int, string>>> p;
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int tmp1 = 0;
		string tmp2;
		cin >> tmp1 >> tmp2;
		p.emplace_back(i, pair<int, string>{tmp1, tmp2});
	}

	sort(p.begin(), p.end(), [](pair<int, pair<int, string>> a, pair<int, pair<int, string>> b) {
		if (a.second.first != b.second.first) return a.second.first < b.second.first;
		return a.first < b.first;
		});

	for (int i = 0; i < p.size(); i++)
		cout << p[i].second.first << " " << p[i].second.second << '\n';

	return 0;
}