#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<deque>

using namespace std;

int main() {
	string s;
	vector<int> v;
	cin >> s;

	for (auto c : s) {
		if (isdigit(c)) v.push_back(c - 48);
	}
	sort(v.begin(), v.end(), greater<int>());
	for (int i : v) cout << i;

	return 0;
}