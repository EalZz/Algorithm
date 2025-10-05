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
long long memo[101][10];
//long long memo[100001];
long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 1; i <= 9; i++) memo[1][i] = 1;

    for (int i = 2; i <= T; i++) {
        memo[i][0] = memo[i - 1][1] % MOD;
        memo[i][9] = memo[i - 1][8] % MOD;
        for (int j = 1; j <= 8; j++) memo[i][j] = (memo[i - 1][j - 1] + memo[i - 1][j + 1]) % MOD;
    }

    int result = 0;
    for (int i = 0; i <= 9; i++) result = (result + memo[T][i]) % MOD;

    cout << result;

    return 0;
}