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
long long memo[10001];

bool bellmanFord(int N, vector<vector<pair<int, int>>>& road);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    vector<vector<int>> v(T, vector<int>(N, 1));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    vector<vector<vector<bool>>> isVisited(T, vector<vector<bool>>(N, vector<bool>(2, false)));

    string tmp;
    for (int row = 0; row < T; row++) {
        cin >> tmp;
        for (int col = 0; col < N; col++) v[row][col] = tmp[col] - '0';
    }
    
    queue<pair<pair<int, int>, pair<int, int>>> q;
    q.push({ {0, 0}, {0, 1} });
    isVisited[0][0][0] = true;

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    while (!q.empty()) {
        pair<int, int> corLoca = q.front().first;
        int wallbreak = q.front().second.first;
        int curLevel = q.front().second.second;
        q.pop();

        if (corLoca.first == T - 1 && corLoca.second == N - 1) {
            cout << curLevel;
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int ny = corLoca.first + dy[i];
            int nx = corLoca.second + dx[i];

            if (ny >= 0 && nx >= 0 && ny < T && nx < N) {
                if (v[ny][nx] == 0 && !isVisited[ny][nx][wallbreak]) {
                    isVisited[ny][nx][wallbreak] = true;
                    q.push({ { ny, nx }, { wallbreak, curLevel + 1 } });
                }
                else if (v[ny][nx] == 1 && wallbreak == 0) {
                    isVisited[ny][nx][1] = true;
                    q.push({ { ny, nx }, { wallbreak + 1, curLevel + 1 } });
                }
            }
        }
    }

    cout << -1;

    return 0;
}

