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

int bfs(int start, vector<vector<int>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T + 1, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];

    int left = 0, right = 0, sum = 0, minLen = 1e9;
    while (1) {

        if (sum >= N) {
            minLen = min(minLen, right - left);
            sum -= v[left++];
        }
        else {
            if (right == T) break;
            sum += v[right++];
        }
    }

    if (minLen == 1e9) cout << 0;
    else cout << minLen;

    return 0;
}