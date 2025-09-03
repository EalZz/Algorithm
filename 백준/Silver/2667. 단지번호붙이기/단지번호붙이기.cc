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
int memo[21][21][21];
//int memo[10000001];
void dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited, vector<int>& dangi, int T);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    vector<int> dangi;

    string tmp;
    for (int row = 0; row < T; row++) {
        cin >> tmp; 
        for (int col = 0; col < T; col++) v[row][col] = tmp[col] - '0';
    }
    
    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) {
            if (!isVisited[row][col] && v[row][col] == 1) {
                isVisited[row][col] = true;
                cnt++;
                dangi.push_back(1);
                dfs(row, col, v, isVisited, dangi, T);
            }
        }
    }

    sort(dangi.begin(), dangi.end());
    cout << cnt << '\n';
    for (int i = 0; i < dangi.size(); i++) cout << dangi[i] << '\n';
    
    return 0;
}

void dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isVisited, vector<int>& dangi, int T) {
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };

    for (int i = 0; i < 4;i++) {
        int nx = col + dx[i];
        int ny = row + dy[i];

        if (nx >= 0 && ny >= 0 && nx < T && ny < T && v[ny][nx] == 1 && !isVisited[ny][nx]) {
            isVisited[ny][nx] = true;
            dangi.back() += 1;
            dfs(ny, nx, v, isVisited, dangi, T);
        }
    }
    return;
}