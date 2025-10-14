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
//long long memo[3];
//int memo[1001][3];
//long long memo[1000001];
//long long MOD = 1000000000;
int memo[1000001][5][5];
char starDr[10000][10000];

void star(int N, int row, int col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    //int M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<vector<int>> v(N);
    //vector<bool> isVisited(4000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    memset(starDr, ' ', sizeof(starDr));

    star(N, 0, N - 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) cout << starDr[i][j];
        cout << '\n';
    }

    return 0;
}

void star(int N, int row, int col) {
    if (N == 3) {
        starDr[row][col] = '*';

        starDr[row + 1][col - 1] = '*';
        starDr[row + 1][col + 1] = '*';

        for (int i = 0; i < 5; i++) starDr[row + 2][col - 2 + i] = '*';
        return;
    }

    star(N / 2, row, col);
    star(N / 2, row + N / 2, col - N / 2);
    star(N / 2, row + N / 2, col + N / 2);
}
