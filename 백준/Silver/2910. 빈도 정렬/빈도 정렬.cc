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

    int n, c; cin >> n >> c;

    vector<pair<int, pair<int, int>>> num;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        int k;
        for (k = 0; k < num.size(); k++)
            if (num[k].second.second == val)
            {
                num[k].second.first++;
                break;
            }

        if (k == num.size()) num.push_back({ i, {1, val} });
    }

    sort(num.begin(), num.end(), [](pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
        if (a.second.first != b.second.first) return a.second.first > b.second.first;
        return a.first < b.first;
    });

    for (auto x : num)
        while (x.second.first--) cout << x.second.second << ' ';

    return 0;
}