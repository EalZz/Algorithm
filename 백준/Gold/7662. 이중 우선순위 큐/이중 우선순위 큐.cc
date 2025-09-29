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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(101, 0);
    //vector<vector<char>> v(T, vector<char>(T, 0));
    //vector<bool> isVisited(101, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        multiset<int> ms;

        int a; cin >> a;
        while (a--) {
            char cmd;
            int num;
            cin >> cmd >> num;

            if (cmd == 'I') ms.insert(num);
            else if (cmd == 'D') {
                if (!ms.empty()) {
                    if (num == 1) ms.erase(prev(ms.end()));
                    else if (num == -1) ms.erase(ms.begin());
                }
            }
        }
        if (!ms.empty()) cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
        else cout << "EMPTY" << '\n';
    }

    return 0;
}