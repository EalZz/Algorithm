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
void dfs(int N, vector<int>& v, vector<int>& tmp, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0;
    vector<int> v(T);
    vector<int> tmp;
    vector<bool> isVisited(T, false);
    //vector<vector<int>> v(T, vector<int>(T));
    for (int i = 0; i < T; i++) cin >> v[i];
    sort(v.begin(), v.end());

    dfs(N, v, tmp, isVisited);

    return 0;
}

void dfs(int N, vector<int>& v, vector<int>& tmp, vector<bool>& isVisited) {
    if (tmp.size() == N) {
        for (int i = 0; i < tmp.size(); i++) cout << tmp[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < v.size(); i++) {
        if (!isVisited[i] && (tmp.empty() || tmp.back() < v[i])) {
            isVisited[i] = true;
            tmp.push_back(v[i]);

            dfs(N, v, tmp, isVisited);

            isVisited[i] = false;
            tmp.pop_back();
        }
    }
    return;
}