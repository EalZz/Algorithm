#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    deque<pair<int, int>> d;
    d.resize(N);
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        d[i].first = i + 1;
        d[i].second = tmp;
    }

    int idx = 1;
    while (!d.empty()) {
        if (idx > 0) {
            for (int i = 0; i < idx - 1; i++) {
                d.push_back(d.front());
                d.pop_front();
            }

            idx = d.front().second;
            cout << d.front().first << " ";
            d.pop_front();
        }
        else {
            for (int i = 0; i > idx + 1; i--) {
                d.push_front(d.back());
                d.pop_back();
            }

            idx = d.back().second;
            cout << d.back().first << " ";
            d.pop_back();
        }
    }

    return 0;
}