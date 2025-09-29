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

void dfs(int N, int pre, vector<int>& v, vector<int>& result);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(T);
    vector<bool> isVisited(T, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    set<int> s;
    for (int i = 0; i < T; i++) {
        int tmp; cin >> tmp;
        s.insert(tmp);
    }
    vector<int> v(s.begin(), s.end());
    vector<int> result;

    dfs(N, 0, v, result);

    return 0;
}

void dfs(int N, int pre, vector<int>& v, vector<int>& result) {
    if (result.size() == N) {
        for (auto& i : result) cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!result.empty() && result.back() > v[i]) continue;
        result.push_back(v[i]);
        dfs(N, pre, v, result);
        result.pop_back();
    }
    return;
}