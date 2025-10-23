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
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];
int memo[1001];

void dfs(int idx, vector<vector<int>>& v);
void move(int dir, vector<vector<int>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<vector<int>> v(N, vector<int>(N));
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) cin >> v[row][col];
    }

    dfs(0, v);
    cout << cnt;

    return 0;
}

void dfs(int idx, vector<vector<int>>& v) {
    if (idx == 5) {
        int tmp = 0;
        for (int row = 0; row < v.size(); row++) {
            for (int col = 0; col < v.size(); col++) tmp = max(tmp, v[row][col]);
        }
        cnt = max(cnt, tmp);
        return;
    }

    for (int i = 0; i < 4; i++) {
        vector<vector<int>> tmp = v;
        move(i, tmp);
        dfs(idx + 1, tmp);
    }
}

void move(int dir, vector<vector<int>>& v) {
    int n = v.size();
    switch (dir)
    {
    case 0: 
        for (int col = 0; col < n; col++) {
            vector<int> tmp;
            for (int row = 0; row < n; row++)
                if (v[row][col] != 0) tmp.push_back(v[row][col]);

            vector<int> newCol;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    newCol.push_back(tmp[i] * 2);
                    i++; 
                }
                else {
                    newCol.push_back(tmp[i]);
                }
            }
            while (newCol.size() < n) newCol.push_back(0);
            for (int row = 0; row < n; row++) v[row][col] = newCol[row];
        }
        break;

    case 1: 
        for (int col = 0; col < n; col++) {
            vector<int> tmp;
            for (int row = n - 1; row >= 0; row--)
                if (v[row][col] != 0) tmp.push_back(v[row][col]);

            vector<int> newCol;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    newCol.push_back(tmp[i] * 2);
                    i++;
                }
                else {
                    newCol.push_back(tmp[i]);
                }
            }
            while (newCol.size() < n) newCol.push_back(0);
            for (int row = n - 1, idx = 0; row >= 0; row--, idx++)
                v[row][col] = newCol[idx];
        }
        break;

    case 2: 
        for (int row = 0; row < n; row++) {
            vector<int> tmp;
            for (int col = 0; col < n; col++)
                if (v[row][col] != 0) tmp.push_back(v[row][col]);

            vector<int> newRow;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    newRow.push_back(tmp[i] * 2);
                    i++;
                }
                else {
                    newRow.push_back(tmp[i]);
                }
            }
            while (newRow.size() < n) newRow.push_back(0);
            for (int col = 0; col < n; col++) v[row][col] = newRow[col];
        }
        break;

    case 3: 
        for (int row = 0; row < n; row++) {
            vector<int> tmp;
            for (int col = n - 1; col >= 0; col--)
                if (v[row][col] != 0) tmp.push_back(v[row][col]);

            vector<int> newRow;
            for (int i = 0; i < tmp.size(); i++) {
                if (i + 1 < tmp.size() && tmp[i] == tmp[i + 1]) {
                    newRow.push_back(tmp[i] * 2);
                    i++;
                }
                else {
                    newRow.push_back(tmp[i]);
                }
            }
            while (newRow.size() < n) newRow.push_back(0);
            for (int col = n - 1, idx = 0; col >= 0; col--, idx++)
                v[row][col] = newRow[idx];
        }
        break;
    }
    return;
}
