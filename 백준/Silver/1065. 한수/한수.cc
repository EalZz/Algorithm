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
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (i < 100) {
			ans++;
			continue;
		}
		if (i == 1000) continue;

		int num[3] = { 0, };
		int t = i;

		for (int j = 0; j < 3; j++) {
			num[j] = t % 10;
			t /= 10;
		}

		if (num[0] - num[1] == num[1] - num[2]) ans++;
	}

	cout << ans;

    return 0;
}