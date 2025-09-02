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
int memo[21][21][21];
//int memo[10000001];

void dfs(int c, vector<vector<int>>& edge, vector<bool>& isVisited);
void bfs(int c, vector<vector<int>>& edge, queue<int>& q, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> maze (T, vector<int>(N));
    vector<vector<int>> level(T, vector<int>(N));
    vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    queue<pair<int, int>> q;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    
    string tmp;
    for (int row = 0; row < T; row++) {
        cin >> tmp;
        for (int col = 0; col < N; col++) maze[row][col] = tmp[col] - '0';
    }

    q.push({ 0, 0 });
    isVisited[0][0] = true;
    level[0][0] = 1;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int cx = current.first + dx[i];
            int cy = current.second + dy[i];

            if (cx >= 0 && cy >= 0 && cx < T && cy < N && maze[cx][cy] == 1 && !isVisited[cx][cy]) {
                isVisited[cx][cy] = true;
                q.push({ cx, cy });
                level[cx][cy] = level[current.first][current.second] + 1;
            }
        }
    }

    cout << level[T - 1][N - 1];

    return 0;
}
