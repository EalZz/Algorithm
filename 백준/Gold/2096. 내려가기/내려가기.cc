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
int cnt = 0, cnt1 = 0;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(N + 1);
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int x, y, z; cin >> x >> y >> z;
    int maxm[3] = { x, y, z }, minm[3] = { x, y, z };

    for (int i = 1; i < T; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int preMax[3] = { maxm[0], maxm[1], maxm[2] };
        int preMin[3] = { minm[0], minm[1], minm[2] };

        maxm[0] = a + max(preMax[0], preMax[1]);
        maxm[1] = b + max(max(preMax[0], preMax[1]), preMax[2]);
        maxm[2] = c + max(preMax[1], preMax[2]);

        minm[0] = a + min(preMin[0], preMin[1]);
        minm[1] = b + min(min(preMin[0], preMin[1]), preMin[2]);
        minm[2] = c + min(preMin[1], preMin[2]);
    }

    cout << max(max(maxm[0], maxm[1]), maxm[2]) << ' ' << min(min(minm[0], minm[1]), minm[2]);

    return 0;
}