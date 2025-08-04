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
int cnt = 0;
void subset(vector<int> v, int K, int idx, int sum);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0, K = 0; 
    cin >> N >> K;
    //int T = 0; cin >> T;
    vector<int> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];

    subset(v, K, 0, 0);
    cout << cnt;

    return 0;
}

void subset(vector<int> v, int K, int idx, int sum) {
    if (idx >= v.size()) return;

    subset(v, K, idx + 1, sum);

    sum += v[idx];
    subset(v, K, idx + 1, sum);
    if (sum == K) cnt++;

    return;
}