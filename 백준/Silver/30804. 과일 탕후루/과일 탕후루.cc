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
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T, 0);
    //vector<vector<char>> v(T, vector<char>(N, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];

    map<int, int> count;

    int idx = 0;
    for (int i = 0; i < T; i++) {
        count[v[i]]++;

        while (count.size() > 2) {
            count[v[idx]]--;
            if (count[v[idx]] == 0) count.erase(v[idx]);
            idx++;
        }
        cnt = max(cnt, i - idx + 1);
    }

    cout << cnt;

    return 0;
}
