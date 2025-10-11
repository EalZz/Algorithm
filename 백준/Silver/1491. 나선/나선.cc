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
int cnt = 1, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//long long memo[101][10];
long long memo[100001];
//long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    int M = 0; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<long long> v(T + 1, 0);
    vector<vector<int>> v(M, vector<int>(N, 0));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int dy[4] = { 0, 1, 0, -1 };
    int dx[4] = { 1, 0, -1, 0 };

    int row = 0, col = 0, idx = 0;
    v[0][0] = 1;
    while (cnt < N * M) {
        int ny = row + dy[idx];
        int nx = col + dx[idx];

        if (ny < 0 || nx < 0 || ny >= M || nx >= N || v[ny][nx]) {
            if (idx == 3) idx = 0;
            else idx++;
            continue;
        }
        v[ny][nx] = 1;
        row = ny;
        col = nx;
        cnt++;
    }

    cout << col << ' ' << row;

    return 0;
}
