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
	vector<pair<int, int>> p;
	int T = 0;
	cin >> T;

	while (T--) {
		int tmp1 = 0, tmp2 = 0;
		cin >> tmp1 >> tmp2;
		p.emplace_back(tmp1, tmp2);
	}
	
	sort(p.begin(), p.end(), [](pair<int, int> a, pair<int, int> b) {
		if (a.second != b.second) return a.second < b.second;
		else return a.first < b.first;
		});

	for (int i = 0; i < p.size(); i++)
		cout << p[i].first << " " << p[i].second << '\n';
	
	return 0;
}