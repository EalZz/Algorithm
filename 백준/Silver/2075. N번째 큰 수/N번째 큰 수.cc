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

void dfs(int N, vector<int>& ans, vector<bool> isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<int> v(N * N);
    for (int i = 0; i < N * N; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());

    cout << v[N - 1] << endl;

    return 0;
}