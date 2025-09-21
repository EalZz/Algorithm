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
//int cnt = 0, cnt1 = 1e9;
//int memo[21][21][21];
//long long memo[101];
int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<int> tmp;
    vector<vector<int>> v(T + 1, vector<int>(T + 1, 0));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int row = 1; row <= T; row++) {
        for (int col = 1; col <= T; col++) {
            cin >> v[row][col];
            v[row][col] += v[row][col - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> y1 >> x1 >> y2 >> x2;

        int sum = 0;
        for (int row = y1; row <= y2; row++) {
            sum += v[row][x2] - v[row][x1 - 1];
        }
        cout << sum << '\n';
    }
    return 0;
}