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
//long long memo[101];
int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v;
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int MOD = 10;
    int sum = 0, idx = 0;

    for (int i = 0; i < 13; i++) {
        char tmp; cin >> tmp;

        if (tmp == '*') {
            idx = i;
            continue;
        }

        if (i % 2 == 0) sum += tmp - '0';
        else sum += ((tmp - '0') * 3) % MOD;
    }
    sum %= MOD;

    if (sum == 0) cout << 0;
    else if (idx % 2 == 0) cout << 10 - sum;
    else {
        for (int i = 0; i < 9;i++) {
            if ((i * 3 + sum) % 10 == 0) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}