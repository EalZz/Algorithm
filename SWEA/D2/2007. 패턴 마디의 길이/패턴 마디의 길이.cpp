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
//int memo[21][21][21];
//int memo[10000001];

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; t++) {
        string str, tmp = "";
        int j = 0;
        cin >> str;

        for (int i = 1; i < str.size(); ++i) {
            if (str[i] == str[j]) j++;
            else j = 0;
        }
        cout << "#" << t << ' ' << str.size() - j << '\n';
	}

	return 0;
}