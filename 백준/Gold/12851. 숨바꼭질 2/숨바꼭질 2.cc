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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N , 0);
    //vector<vector<long long>> v(N, vector<long long>(N));
    vector<bool> isVisited(100001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int time = 0, count = 0;

    queue<pair<int, int>> q;
    q.push({ N, 0 });
    isVisited[N] = true;

    while (!q.empty()) {
        int curLoca = q.front().first;
        int curTime = q.front().second;
        q.pop();
        isVisited[curLoca] = true;

        if (curLoca == M) {
            if (time == 0) {
                time = curTime;
                count++;
            }
            else if (curTime == time) count++;
        }

        if (curLoca + 1 < 100001 && !isVisited[curLoca + 1])
            q.push({ curLoca + 1, curTime + 1 });

        if (curLoca - 1 >= 0 && !isVisited[curLoca - 1])
            q.push({ curLoca - 1, curTime + 1 });

        if (curLoca * 2 < 100001 && !isVisited[curLoca * 2])
            q.push({ curLoca * 2, curTime + 1 });
    }

    cout << time << '\n' << count;

    return 0;
}
