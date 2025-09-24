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

    set<int> s;
    while (T--) {
        string str; cin >> str;
        if (str == "add") {
            int num; cin >> num;
            s.insert(num);
        }
        else if (str == "remove") {
            int num; cin >> num;
            if (binary_search(s.begin(), s.end(), num)) s.erase(num);
        }
        else if (str == "check") {
            int num; cin >> num;
            if (binary_search(s.begin(), s.end(), num)) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if (str == "toggle") {
            int num; cin >> num;
            if (binary_search(s.begin(), s.end(), num)) s.erase(num);
            else s.insert(num);
        }
        else if (str == "all") {
            for (int i = 1; i <= 20; i++) s.insert(i);
        }
        else if (str == "empty") s.clear();
   }


    return 0;
}