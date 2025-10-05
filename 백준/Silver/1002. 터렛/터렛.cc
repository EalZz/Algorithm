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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        vector<int> v(6);
        long long x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        if (x1 == x2 && y1 == y2) {
            if (r1 == r2) cout << -1 << '\n';
            else cout << 0 << '\n';
        }
        else {
            if (pow(x1 - x2, 2) + pow(y1 - y2, 2) == pow(r1 + r2, 2)) cout << 1 << '\n';
            else if (pow(x1 - x2, 2) + pow(y1 - y2, 2) == pow(r1 - r2, 2)) cout << 1 << '\n';
            else if (pow(x1 - x2, 2) + pow(y1 - y2, 2) > pow(r1 + r2, 2)) cout << 0 << '\n';
            else if (pow(x1 - x2, 2) + pow(y1 - y2, 2) < pow(r1 - r2, 2)) cout << 0 << '\n';
            else cout << 2 << '\n';
        }
    }
    return 0;
}