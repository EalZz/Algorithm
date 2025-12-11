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
    
    int N, M; cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(N, 0));
    int row, col;
    row = col = N / 2;
    v[row][col] = 1;
    
    int dy[] = {-1, 0, 1, 0};
    int dx[] = {0, 1, 0, -1};
    int idx = 3;
    int r = -1, c = -1;
    
    if (M == 1) {
        r = row + 1;
        c = col + 1;
    }
    
    for (int i = 2; i <= N * N; i++) {
        int nextIdx = (idx + 1) % 4;
        int nextRow = row + dy[nextIdx];
        int nextCol = col + dx[nextIdx];
        
        if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < N && v[nextRow][nextCol] == 0)
            idx = nextIdx;
        
        row = row + dy[idx];
        col = col + dx[idx];
        v[row][col] = i;
        
        if (i == M) {
            r = row + 1;
            c = col + 1;
        }
    }
    
    for (auto& c : v) {
        for (auto& i : c) cout << i << ' ';
        cout << '\n';
    }
    cout << r << ' ' << c;
    
    return 0;
}