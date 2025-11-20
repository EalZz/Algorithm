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
#include <list>

using namespace std;

int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };

int bfs(int row, int col, int cnt, vector<vector<bool>>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++) cin >> v[i];
    vector<vector<bool>> isVisited(N, vector<bool>(N, false));

    bool isAble = true;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < v[row].size(); col++) {
            if (isVisited[row][col]) continue;

            if (v[row][col] == 'R') {
                if (row + 1 >= N || col + 1 >= N || v[row + 1][col] != 'R' || v[row + 1][col + 1] != 'R' || 
                    isVisited[row + 1][col] || isVisited[row + 1][col + 1]) {
                    isAble = false;
                    break;
                }
                isVisited[row + 1][col] = true;
                isVisited[row + 1][col + 1] = true;
            }
            else {
                if (row + 1 >= N || col + 1 >= N || v[row][col + 1] != 'B' || v[row + 1][col + 1] != 'B' ||
                    isVisited[row][col + 1] || isVisited[row + 1][col + 1]) {
                    isAble = false;
                    break;
                }
                isVisited[row][col + 1] = true;
                isVisited[row + 1][col + 1] = true;
            }
        }
        if (!isAble) break;
    }

    if (isAble) cout << 1;
    else cout << 0;

    return 0;
}
