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
//long long memo[101];
int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T, 0);
    //vector<int> tmp;
    //vector<vector<int>> v(T, vector<int>(2, 0));
    vector<pair<int, int>> v(T);
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    
    for (int row = 0; row < T; row++) {
        int a, b; cin >> a >> b;
        v[row] = { a, b };
    }

    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
        });

    cnt++;
    pair<int, int> cur = v[0];
    for (int i = 1; i < v.size(); i++) {
        pair<int, int> next = v[i];
        if (next.first >= cur.second) {
            cur = next;
            cnt++;
        }
    }

    cout << cnt;


    return 0;
}