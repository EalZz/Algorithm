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
//long long memo[1001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int N = 0; cin >> N;
    int T = 0; cin >> T;
    int X = 0; cin >> X;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(T, vector<int>(N, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<vector<vector<int>>> v(X, vector<vector<int>>(T, vector<int>(N, 0)));
    vector<vector<vector<bool>>> isVisited(X, vector<vector<bool>>(T, vector<bool>(N, false)));

    vector<tuple<int, int, int>> start;
    for (int high = 0; high < X; high++) {
        for (int row = 0; row < T; row++) {
            for (int col = 0; col < N; col++) {
                cin >> v[high][row][col];
                if (v[high][row][col] == 1) {
                    start.push_back({ high, row, col });
                    isVisited[high][row][col] = true;
                }
                if (v[high][row][col] == -1) isVisited[high][row][col] = true;
            }
        }
    }
    queue<pair<tuple<int, int, int>, int>> q;
    for (int i = 0; i < start.size(); i++) {
        q.push({{get<0>(start[i]), get<1>(start[i]), get<2>(start[i])}, 0 });
        v[get<0>(start[i])][get<1>(start[i])][get<2>(start[i])] = 0;
    }

    int dz[6] = { 0, 0, 0, 0, 1, -1 };
    int dy[6] = { 0, 0, 1, -1, 0, 0 };
    int dx[6] = { 1, -1, 0, 0, 0, 0 };

    while (!q.empty()) {
        tuple<int, int, int> curLoca = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            if (get<0>(curLoca) + dz[i] >= 0 && get<1>(curLoca) + dy[i] >= 0 && get<2>(curLoca) + dx[i] >= 0 
                && get<0>(curLoca) + dz[i] < X && get<1>(curLoca) + dy[i] < T && get<2>(curLoca) + dx[i] < N
                && !isVisited[get<0>(curLoca) + dz[i]][get<1>(curLoca) + dy[i]][get<2>(curLoca) + dx[i]]) {
                isVisited[get<0>(curLoca) + dz[i]][get<1>(curLoca) + dy[i]][get<2>(curLoca) + dx[i]] = true;

                v[get<0>(curLoca) + dz[i]][get<1>(curLoca) + dy[i]][get<2>(curLoca) + dx[i]] += curLevel;
                q.push({ {get<0>(curLoca) + dz[i], get<1>(curLoca) + dy[i], get<2>(curLoca) + dx[i]}, curLevel + 1 });
                cnt = curLevel + 1;
            }
        }
    }

    bool isAble = true;
    for (int high = 0; high < X; high++) {
        for (int row = 0; row < T; row++) {
            for (int col = 0; col < N; col++) {
                if (!isVisited[high][row][col]) {
                    isAble = false;
                    break;
                }
            }
            if (!isAble) break;
        }
        if (!isAble) break;
    }

    if (isAble) cout << cnt;
    else cout << -1;

    return 0;
}