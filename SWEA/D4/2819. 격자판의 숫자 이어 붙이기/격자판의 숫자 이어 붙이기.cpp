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

using namespace std;

void dfs(int row, int col, int cnt, string s, set<string>& ss, vector<vector<char>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        vector<vector<char>> v(4, vector<char>(4));
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) cin >> v[row][col];
        }

        set<string> ss;
        for (int row = 0; row < 4; row++) {
            for (int col = 0; col < 4; col++) dfs(row, col, 0, string(1, v[row][col]), ss, v);
        }

        cout << "#" << t << " ";
        cout << ss.size();
        cout << '\n';
    }
    return 0;
}

void dfs(int row, int col, int cnt, string s, set<string>& ss, vector<vector<char>>& v) {
    if (cnt == 6) {
        ss.insert(s);
        return;
    }
    
    int dy[4] = { 1, -1, 0, 0 };
    int dx[4] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4; i++) {
        int nrow = row + dy[i]; 
        int ncol = col + dx[i];

        if (nrow >= 4 || ncol >= 4 || nrow < 0 || ncol < 0) continue;

        dfs(nrow, ncol, cnt + 1, s + v[nrow][ncol], ss, v);
    }
    return;
}