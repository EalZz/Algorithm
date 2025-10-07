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
//long long memo[101][10];
//long long memo[100001];
//long long MOD = 1000000000;

bool dfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& brow, vector<vector<bool>>& bcol, vector<vector<bool>>& bbox);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string str1, str2, result = "";
    cin >> str1 >> str2;

    int strlen1 = str1.size(), strlen2 = str2.size();
    vector<vector<int>> v(strlen1 + 1, vector<int>(strlen2 + 1, 0));

    for (int row = 1; row <= strlen1; row++) {
        for (int col = 1; col <= strlen2; col++) {
            if (str1[row - 1] == str2[col - 1]) v[row][col] = v[row - 1][col - 1] + 1;
            else v[row][col] = max(v[row - 1][col], v[row][col - 1]);
        }
    }

    int i = strlen1, j = strlen2;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result.push_back(str1[i - 1]);
            i--;
            j--;
        }
        else if (v[i - 1][j] >= v[i][j - 1]) i--;
        else j--;
    }

    reverse(result.begin(), result.end());
    cout << v[strlen1][strlen2] << '\n' << result;

    return 0;
}