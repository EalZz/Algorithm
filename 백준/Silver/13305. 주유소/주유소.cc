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
//int memo[21][21][21];
//long long memo[101];
int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<long long> v(T);
    vector<long long> tmp(T - 1);
    //vector<vector<int>> v(T, vector<int>(2, 0));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T - 1; i++) cin >> tmp[i];
    for (int i = 0; i < T; i++) {
        int vtmp; cin >> vtmp;
        if (i > 0 && vtmp > v[i - 1]) v[i] = v[i - 1];
        else v[i] = vtmp;
    }

    long long result = 0;
    for (int i = 0; i < T - 1;i++) result += v[i] * tmp[i];
    cout << result;

    return 0;
}