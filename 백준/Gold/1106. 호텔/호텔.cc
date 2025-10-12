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
//long long memo[101][10];
long long memo[100001];
//long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int M = 0; cin >> M;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<long long> v(T + 1, 0);
    vector<vector<int>> v(N, vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    fill(memo, memo + 100001, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) cin >> v[i][j];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= 100000; j++) {
            int curCost = v[i][0];
            int curCus = v[i][1];

            if (j >= curCost) memo[j] = max(memo[j], memo[j - curCost] + curCus);
        }
    }

    cout << lower_bound(memo, memo + 100001, M) - memo;

    return 0;
}