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

void dfs(int row, int node, vector<vector<int>>& v, vector<bool>& isVisited, vector<vector<int>>& newv);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v;
    //vector<vector<int>> v(T);
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        deque<int> v;
        string cmd, tmp;
        int N;
        cin >> cmd >> N >> tmp;

        int tmpi = 0;
        for (auto& c : tmp) {
            if (!isdigit(c)) {
                if (tmpi == 0) continue;
                v.push_back(tmpi);
                tmpi = 0;
                continue;
            }
            tmpi = tmpi * 10 + (c - '0');
        }

        bool isReverse = false;
        bool isError = false;
        for (auto& c : cmd) {
            if (c == 'R') isReverse = !isReverse;
            else if (c == 'D') {
                if (v.size() == 0) {
                    isError = true;
                    break;
                }
                if (!isReverse) v.pop_front();
                else v.pop_back();
            }
        }
        if (isError) cout << "error" << '\n';
        else {
            cout << '[';
            if (v.empty()) cout << ']' << '\n';
            else if (!isReverse) {
                for (int i = 0; i < v.size() - 1; i++) cout << v[i] << ',';
                cout << v.back() << ']' << '\n';;
            }
            else {
                for (int i = v.size() - 1; i > 0; i--) cout << v[i] << ',';
                cout << v.front() << ']' << '\n';;
            }
        }
    }

    return 0;
}
