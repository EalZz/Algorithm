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
//long long memo[1001];
//int memo[101][4];

void dfs(int N, vector<int>& v, vector<int>& result, vector<bool>& isVisited, set<vector<int>>& s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T);
    //vector<vector<int>> v(T);
    vector<bool> isVisited(T, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];

    sort(v.begin(), v.end()); 
    vector<int> result;
    set<vector<int>> s;

    dfs(N, v, result, isVisited, s);
    
    for (auto& n : s) {
        for (auto& m : n) cout << m << ' ';
        cout << '\n';
    }

    return 0;
}

void dfs(int N, vector<int>& v, vector<int>& result, vector<bool>& isVisited, set<vector<int>>& s) {
    if (result.size() == N) {
        s.insert(result);
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (isVisited[i]) continue;

        isVisited[i] = true;
        result.push_back(v[i]);

        dfs(N, v, result, isVisited, s);

        isVisited[i] = false;
        result.pop_back();
    }
    return;
}