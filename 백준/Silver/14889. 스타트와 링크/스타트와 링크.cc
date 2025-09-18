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
//int memo[21][21][21];
//int memo[10000001];

void dfs(int idx, vector<int>& team1, vector<vector<int>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<int> tmp;
    vector<vector<int>> v(T, vector<int>(T));
    vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    vector<int> team1;

    for (int row = 0; row < T; row++) {
        for (int col = 0; col < T; col++) cin >> v[row][col];
    }

    dfs(0, team1, v, isVisited);

    cout << cnt1;

    return 0;
}

void dfs(int idx, vector<int>& team1, vector<vector<int>>& v, vector<bool>& isVisited) {
    if (team1.size() == v.size() / 2) {
        vector<int> team2;
        int t1 = 0, t2 = 0;
      
        for (int i = 0; i < v.size(); i++) {
            if (!isVisited[i]) team2.push_back(i);
        }

        for (int i = 0; i < team1.size() - 1; i++) {
            for (int j = i + 1; j < team1.size(); j++) {
                t1 += v[team1[i]][team1[j]] + v[team1[j]][team1[i]];
                t2 += v[team2[i]][team2[j]] + v[team2[j]][team2[i]];
            }
        }

        cnt1 = min(cnt1, abs(t1 - t2));

        return;
    }

    for(int i = idx; i < v.size(); i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            team1.push_back(i);

            dfs(i + 1, team1, v, isVisited);

            isVisited[i] = false;
            team1.pop_back();
        }
    }
    
    return;
}
