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
    int a = 0, b = 0, c = 0; //cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v1(a, vector<int>(b));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    cin >> a >> b;
    vector<vector<int>> v1(a, vector<int>(b));
    for (int row = 0; row < a; row++) {
        for (int col = 0; col < b; col++) cin >> v1[row][col];
    }

    cin >> b >> c;
    vector<vector<int>> v2(b, vector<int>(c));
    for (int row = 0; row < b; row++) {
        for (int col = 0; col < c; col++) cin >> v2[row][col];
    }

    for (int row = 0; row < a; row++) {
        for (int col = 0; col < c; col++) {
            int sum = 0;
            for (int i = 0; i < b; i++) sum += v1[row][i] * v2[i][col];
            cout << sum << ' ';
        }
        cout << '\n';
    }

    return 0;
}
