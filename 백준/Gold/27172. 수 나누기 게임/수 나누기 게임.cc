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
    vector<int> v(N);
    //vector<vector<int>> v(N);
    vector<bool> isVisited(1000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        isVisited[v[i]] = true;
    }

    for (auto& num : v) {
        for (int j = num * 2; j < 1000001; j += num) {
            if (isVisited[j]) {
                memo[j]--;
                memo[num]++;
            }
        }
    }

    for (auto num : v) cout << memo[num] << ' ';

    return 0;
}