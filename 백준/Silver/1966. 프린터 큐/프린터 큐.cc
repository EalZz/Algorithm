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
//long long memo[101];
int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(T, vector<int>(2));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        int a, b; cin >> a >> b;
        cnt = 1;
        priority_queue<int> pq;
        vector<int> v(a);

        for (int i = 0; i < a; i++) {
            int tmp; cin >> tmp;
            pq.push(tmp);
            v[i] = tmp;
        }

        int idx = 0;
        while (1) {
            if (v[idx] == -1) idx++;
            if (idx >= v.size()) idx = 0;

            if (v[idx] == pq.top()) {
                if (idx == b) {
                    cout << cnt << '\n';
                    break;
                }
                v[idx] = -1;
                pq.pop();
                cnt++;
            }
            idx++;
        }
    }

    return 0;
}