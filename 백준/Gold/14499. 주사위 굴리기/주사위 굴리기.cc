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

    int N, M, x, y, K;
    cin >> N >> M >> y >> x >> K;

    vector<vector<int>> v(N, vector<int>(M));
    vector<vector<int>> d_edge(6, vector<int>(4));
    vector<int> die(6, 0);

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) cin >> v[row][col];
    }

    vector<vector<int>> roll = {
        {}, 
        { 4, 5, 2, 3, 1, 0 }, 
        { 5, 4, 2, 3, 0, 1 }, 
        { 3, 2, 0, 1, 4, 5 }, 
        { 2, 3, 1, 0, 4, 5 }  
    };

    int dy[4] = { 0, 0, -1, 1 };
    int dx[4] = { 1, -1, 0, 0 };

    while (K--) {
        int cmd; cin >> cmd;
        int nextRow = y + dy[cmd - 1];
        int nextCol = x + dx[cmd - 1];
        if (nextRow >= N || nextCol >= M || nextRow < 0 || nextCol < 0) continue;

        y = nextRow;
        x = nextCol;

        vector<int> tmp = die;
        for (int i = 0; i < 6; i++) die[i] = tmp[roll[cmd][i]];

        if (v[y][x] == 0)  v[y][x] = die[1];
        else {
            die[1] = v[y][x];
            v[y][x] = 0;
        }

        cout << die[0] << '\n';
    }

    return 0;
}