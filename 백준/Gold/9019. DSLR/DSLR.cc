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
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(101, 0);
    //vector<vector<char>> v(T, vector<char>(T, 0));
    vector<bool> isVisited(10001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        int num1, num2;
        cin >> num1 >> num2;

        queue<pair<int, string>> q;
        q.push({ num1, "" });
        isVisited[num1] = true;

        while (!q.empty()) {
            int curNum = q.front().first;
            string curCmd = q.front().second;
            q.pop();

            if (curNum == num2) {
                cout << curCmd << '\n';
                break;
            }

            int D = curNum * 2 % 10000;
            int S = (curNum == 0) ? 9999 : curNum - 1;
            int L = curNum % 1000 * 10 + curNum / 1000;
            int R = curNum / 10 + curNum % 10 * 1000;

            if (!isVisited[D]) {
                isVisited[D] = true;
                q.push({ D, curCmd + "D" });
            }
            if (!isVisited[S]) {
                isVisited[S] = true;
                q.push({ S, curCmd + "S" });
            }
            if (!isVisited[L]) {
                isVisited[L] = true;
                q.push({ L, curCmd + "L" });
            }
            if (!isVisited[R]) {
                isVisited[R] = true;
                q.push({ R, curCmd + "R" });
            }
        }
        isVisited.assign(10001, false);
    }

    return 0;
}