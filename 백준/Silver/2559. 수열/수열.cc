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
//int cnt = 0, cnt1 = 1e9;
//int memo[21][21][21];
//long long memo[101];
int memo[101][4];

int dfs(int level, int cnt, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T);
    deque<int> q;
    //vector<int> tmp;
    //vector<vector<int>> v(T, vector<int>(4, -1));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int cnt = 0, tmp = 0, maxSeq = -1e9;
    for (int row = 0; row < T; row++) {
        int num; cin >> num;
        tmp += num;
        q.push_back(num);

        if (q.size() == N) {
            maxSeq = max(maxSeq, tmp);
            tmp -= q.front();
            q.pop_front();
        }
    }

    cout << maxSeq;

    return 0;
}