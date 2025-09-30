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
long long memo[100001];

void dijkstra(int start, vector<pair<int, int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(T + 1, vector<int>(3, 0));
    vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    fill(memo, memo + 100001, 1e9);

    vector<pair<int, int>> v(3);
    v[0] = { -1, 1 };
    v[1] = { 1, 1 };
    v[2] = { 2, 0 };
    
    dijkstra(T, v);
    cout << memo[N];

    return 0;
}

void dijkstra(int start, vector<pair<int, int>>& v) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({ 0, start });
    memo[start] = 0;

    while (!pq.empty()) {
        int curTime = pq.top().first;
        int curLoca = pq.top().second;
        pq.pop();

        if (memo[curLoca] < curTime) continue;

        for (int i = 0; i < v.size(); i++) {
            int nextTime = curTime + v[i].second;
            int nextLoca = (i != 2) ? curLoca + v[i].first : curLoca * v[i].first;

            if (nextLoca < 0 || nextLoca > 100000) continue;

            if (memo[nextLoca] > nextTime) {
                memo[nextLoca] = nextTime;
                pq.push({ nextTime, nextLoca });
            }
        }
    }
    return;
}