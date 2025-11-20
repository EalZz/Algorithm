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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int C, R, K ; cin >> C >> R >> K;
    vector<vector<bool>> isVisited(R, vector<bool>(C, false));

    if (K > C * R) {
        cout << 0;
        return 0;
    }

    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    isVisited[0][0] = true;
    K--;

    int col = 0, row = 0, dir = 0;
    while (K--) {
        int nextCol = col + dx[dir];
        int nextRow = row + dy[dir];

        if (nextCol >= C || nextRow >= R || nextCol < 0 || nextRow < 0 || isVisited[nextRow][nextCol]) {
            dir++;
            if (dir == 4) dir = 0;
        }

        col += dx[dir];
        row += dy[dir];
        isVisited[row][col] = true;
    }

    cout << col + 1 << ' ' << row + 1;

    return 0;
}
