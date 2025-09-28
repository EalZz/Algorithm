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
//long long memo[1001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(101, 0);
    //vector<vector<char>> v(T, vector<char>(T, 0));
    vector<bool> isVisited(101, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int tmp1, tmp2;
    for (int i = 0; i < T + N; i++) {
        cin >> tmp1 >> tmp2;
        v[tmp1] = tmp2;
    }

    queue<pair<int, int>> q;
    q.push({ 1, 0 });
    isVisited[1] = true;

    while (!q.empty()) {
        int curLoca = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        if (curLoca == 100) {
            cout << curLevel << '\n';
            break;
        }

        for (int i = 1; i <= 6; i++) {
            int nextLoca = curLoca + i;

            if (nextLoca > 100 || isVisited[nextLoca]) continue;
            if (v[nextLoca] != 0) nextLoca = v[nextLoca];

            q.push({ nextLoca, curLevel + 1 });
            isVisited[nextLoca] = true;
        }
    }

    return 0;
}