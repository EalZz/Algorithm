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
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(T + 1);
    vector<bool> isVisited(100001, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    
    queue<pair<int, int>> q;
    q.push({ T, 0 });
    isVisited[T] = true;

    while (!q.empty()) {
        int curLoca = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        if (curLoca == N) {
            cout << curLevel;
            break;
        }

        if (curLoca + 1 < 100001 && !isVisited[curLoca + 1]) {
            isVisited[curLoca + 1] = true;
            q.push({ curLoca + 1, curLevel + 1 });
        }
        if (curLoca - 1 >= 0 && !isVisited[curLoca - 1]) {
            isVisited[curLoca - 1] = true;
            q.push({ curLoca - 1, curLevel + 1 });
        }
        if (curLoca * 2 < 100001 && !isVisited[curLoca * 2]) {
            isVisited[curLoca * 2] = true;
            q.push({ curLoca * 2, curLevel + 1 });
        }

    }

    return 0;
}