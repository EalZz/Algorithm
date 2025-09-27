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
long long memo[50001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T, 0);
    vector<vector<int>> v(T + 1);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < N; i++) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        v[tmp1].push_back(tmp2);
        v[tmp2].push_back(tmp1);
    }

    int result = 0;
    for (int i = 1; i <= T; i++) {
        queue<pair<int, int>> q;
        vector<bool> isVIsited(T + 1, false);

        q.push({ i, 0 });
        isVIsited[i] = true;

        int curLoca = 0, curLevel = 0, sum = 0;
        while (!q.empty()) {
            curLoca = q.front().first;
            curLevel = q.front().second;
            sum += curLevel;
            q.pop();

            for (auto& next : v[curLoca]) {
                if (!isVIsited[next]) {
                    isVIsited[next] = true;
                    q.push({ next, curLevel + 1 });
                }
            }
        }

        if (sum < cnt1 || (sum == cnt1 && result > i)) { 
            cnt1 = sum;
            result = i; 
        }
    }

    cout << result;

    return 0;
}
