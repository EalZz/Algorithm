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
long long memo[50001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    vector<vector<int>> v(a, vector<int>(b, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 0; row < a; row++) {
        for (int col = 0; col < b; col++) cin >> v[row][col];
    }

    for (int h = 0; h <= 256; h++) {
        int time = 0;
        int inven = c;

        for (int row = 0; row < a; row++) {
            for (int col = 0; col < b; col++) {
                if (h < v[row][col]) {
                    time += 2 * (v[row][col] - h);
                    inven += (v[row][col] - h);
                }
                else if (h > v[row][col]) {
                    time += (h - v[row][col]);
                    inven -= (h - v[row][col]);
                }
            }
        }
        if (inven >= 0 && time <= cnt1) {
            cnt = h;
            cnt1 = time;
        }
    }

    cout << cnt1 << ' ' << cnt;

    return 0;
}
