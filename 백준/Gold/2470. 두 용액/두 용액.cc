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
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int left = 0, right = N - 1, ansl = -1, ansr = -1;
    long long min = 1e10;
    while (left < right) {
        long long sum = v[left] + v[right];
        if (abs(sum) < min) {
            min = abs(sum);
            ansl = v[left];
            ansr = v[right];
        }

        if (sum < 0) left++;
        else right--;
    }

    if (ansl < ansr) cout << ansl << ' ' << ansr;
    else cout << ansr << ' ' << ansl;

    return 0;
}