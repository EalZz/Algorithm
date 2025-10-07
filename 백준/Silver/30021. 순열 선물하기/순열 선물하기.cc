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
//long long memo[100001];
//long long MOD = 1000000000;

bool dfs(int T, int sum, int finalsum, vector<int>& result, vector<bool>& isPrime, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<int> result;

    int finalsum = T * (T + 1) / 2;

    vector<bool> isPrime(finalsum + 1, true);
    if (finalsum >= 0) isPrime[0] = false;
    if (finalsum >= 1) isPrime[1] = false;

    for (int i = 2; i <= finalsum; i++) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= finalsum; j += i) isPrime[j] = false;
        }
    }

    dfs(T, 0, finalsum, result, isPrime, isVisited);

    if (result.size() == T) {
        cout << "YES" << '\n';
        for (auto& i : result) cout << i << ' ';
    }
    else cout << "NO";

    return 0;
}

bool dfs(int T, int sum, int finalsum, vector<int>& result, vector<bool>& isPrime, vector<bool>& isVisited) {
    if (result.size() == T) return true;

    for (int i = 1; i <= T; i++) {
        if (isVisited[i] || isPrime[sum + i]) continue;

        isVisited[i] = true;
        result.push_back(i);

        if (dfs(T, sum + i, finalsum, result, isPrime, isVisited)) return true;

        isVisited[i] = false;
        result.pop_back();
    }
    return false;
}