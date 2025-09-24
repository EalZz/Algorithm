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
    //vector<int> v(8, 0);
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    while (T--) {
        string tmp;  cin >> tmp;

        int sum = 0, dx = 1;
        if (tmp[0] == 'O') sum += dx;
        for (int i = 1; i < tmp.size(); i++) {
            if (tmp[i] == 'O') {
                if (tmp[i - 1] == 'O') dx++;
                sum += dx;
            }
            else dx = 1;
        }
        cout << sum << '\n';
    }

    return 0;
}