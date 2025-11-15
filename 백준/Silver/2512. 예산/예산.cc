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

    int N; cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int M; cin >> M;

    int ans = 0, left = 0, right = v.back();
    while (left <= right) {
        int mid = (left + right) / 2;
        int sum = 0;

        for (int i = 0; i < N; i++) {
            if (v[i] <= mid) sum += v[i];
            else sum += mid;
        }

        if (sum <= M) {
            ans = mid;
            left = mid + 1;
        }
        else right = mid - 1;
    }

    cout << ans;

    return 0;
}