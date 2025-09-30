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
//long long memo[3];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(N + 1);
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string str1, str2;
    cin >> str1 >> str2;

    int strlen1 = str1.size(), strlen2 = str2.size();
    vector<vector<int>> v(strlen1 + 1, vector<int>(strlen2 + 1, 0));

    for (int row = 1; row <= strlen1; row++) {
        for (int col = 1; col <= strlen2; col++) {
            if (str1[row - 1] == str2[col - 1]) v[row][col] = v[row - 1][col - 1] + 1;
            else v[row][col] = max(v[row - 1][col], v[row][col - 1]);
        }
    }

    cout << v[strlen1][strlen2];

    return 0;
}