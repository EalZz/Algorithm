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
//long long memo[3];
//int memo[1001][3];
long long memo[1000001];
//long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    //int M = 0; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v;
    //vector<vector<int>> v(N);
    //vector<bool> isVisited(4000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    vector<bool> isPrime(N + 1, true);

    for (int i = 2; i <= sqrt(N); i++) {
        for (int j = i * 2; j <= N; j += i) isPrime[j] = false;
    }
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) v.push_back(i);
    }

    int start = 0, end = 0, sum = 0, ans = 0;
    while (1) {
        if (sum == N) ans++;

        if (sum < N) {
            if (end == v.size()) break;
            sum += v[end];
            end++;
        }
        else if (sum >= N) {
            sum -= v[start];
            start++;
        }
    }

    cout << ans;

    return 0;
}