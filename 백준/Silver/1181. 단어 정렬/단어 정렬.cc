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
	vector<string> v;
	int T = 0;
	cin >> T;

	while (T--) {
		string s;
		cin >> s;
		v.emplace_back(s);
	}

	sort(v.begin(), v.end(), [](string a, string b) {
		if (a.length() != b.length()) return a.length() < b.length();
		return a < b;
		});

	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	
	return 0;
}