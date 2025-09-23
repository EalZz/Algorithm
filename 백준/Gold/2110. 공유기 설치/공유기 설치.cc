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
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T);
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];
    sort(v.begin(), v.end());

    long long start = 1, end = v.back() - v.front(), mid = 0, result = 0;

    while (start <= end) {
        long long avg = 0;
        mid = (start + end) / 2;

        cnt = 1;
        int prev = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i] - prev >= mid) {
                cnt++;
                prev = v[i];
            }
        }

        if (cnt >= N) {
            start = mid + 1;
            result = max(result, mid);
        }
        else if (cnt < N) end = mid - 1;
    }
    cout << result;

    return 0;
}