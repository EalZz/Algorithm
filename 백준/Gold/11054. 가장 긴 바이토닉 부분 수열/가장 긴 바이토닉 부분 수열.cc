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
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[1000001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    //int M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(N , 0);
    //vector<vector<long long>> v(N, vector<long long>(N));
    //vector<bool> isVisited(4000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    for (int i = 0; i < N; i++) cin >> v[i];

    vector<int> left(N, 1), right(N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) left[i] = max(left[i], left[j] + 1);
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = i + 1; j < N; j++) {
            if (v[j] < v[i]) right[i] = max(right[i], right[j] + 1);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, left[i] + right[i] - 1);
    }

    cout << ans;

    return 0;
}
