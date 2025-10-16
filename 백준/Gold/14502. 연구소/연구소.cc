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
//int memo[1001][3];
//long long memo[1000001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

void dfs(int count, vector<vector<int>>& v, queue<pair<int, int>>& start);
int bfs(vector<vector<int>> v, queue<pair<int, int>> start);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N , 0);
    vector<vector<int>> v(N, vector<int>(M));
    vector<bool> isVisited(100001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    queue<pair<int, int>> start;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> v[row][col];
            if (v[row][col] == 2) start.push({ row, col });
        }
    }

    dfs(0, v, start);

    cout << cnt;

    return 0;
}

void dfs(int count, vector<vector<int>>& v, queue<pair<int, int>>& start) {
    if (count == 3) {
        cnt = max(cnt, bfs(v, start));
        return;
    }
    else {
        for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i][j] != 0) continue;
                v[i][j] = 1;
                dfs(count + 1, v, start);
                v[i][j] = 0;
            }
        }
    }
}

int bfs(vector<vector<int>> v, queue<pair<int, int>> start) {
    queue<pair<int, int>> q = start;

    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    while (!q.empty()) {
        int curRow = q.front().first;
        int curCol = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = curRow + dy[i];
            int nx = curCol + dx[i];

            if (ny >= v.size() || nx >= v[0].size() || ny < 0 || nx < 0 || v[ny][nx] != 0) continue;
            v[ny][nx] = 2;
            q.push({ ny, nx });
        }
    }

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (v[i][j] == 0) ans++;
        }
    }
    return ans;
}