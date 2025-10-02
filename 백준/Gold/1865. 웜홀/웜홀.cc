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
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(T + 1, vector<int>(3, 0));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    //int X; cin >> X;

    while (T--) {
        int N, M, W;
        cin >> N >> M >> W;

        fill(memo, memo +  N + 1, 1e9);
        vector<vector<pair<int, int>>> road(N + 1);
        for (int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;

            road[S].push_back({ E, T });
            road[E].push_back({ S, T });
        }

        for (int i = M; i < M + W; i++) {
            int S, E, T;
            cin >> S >> E >> T;

            road[S].push_back({ E, -T });
        }

        if (bellmanFord(N, road)) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}

bool bellmanFord(int N, vector<vector<pair<int, int>>>& road) {
    for (int i = 1; i <= N; i++) memo[i] = 0;

    for (int a = 0; a < N - 1; a++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j < road[i].size(); j++) {
                int end = road[i][j].first;
                int cost = road[i][j].second;

                if (memo[end] > cost + memo[i]) memo[end] = cost + memo[i];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < road[i].size(); j++) {
            int end = road[i][j].first;
            int cost = road[i][j].second;

            if (memo[i] != 1e9 && memo[end] > cost + memo[i]) return true;
        }
    }
    return false;
}