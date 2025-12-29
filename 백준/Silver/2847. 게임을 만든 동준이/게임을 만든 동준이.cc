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

int bfs(int row, int col, vector<vector<char>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> v(N);
    for (int i = N - 1; i >= 0; i--) cin >> v[i];

    int cnt = 0;
    for (int i = 0; i < N - 1; i++) {
        while (v[i] <= v[i + 1]) {
            v[i + 1]--;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}