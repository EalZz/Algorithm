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
    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v;
    //vector<int> tmp;
    //vector<vector<int>> v(T, vector<int>(2, 0));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    string s; cin >> s;
    string tmp = "";
    bool isMinus = false;
    int result = 0;

    int idx = 0;
    int midx = 0;
    for (auto& c : s) {
        if (isdigit(c)) tmp.push_back(c);
        else {
            v.push_back(stoi(tmp));
            idx++;
            tmp.clear();
            if (c == '-' && midx == 0) {
                isMinus = true;
                midx = idx;
            }
        }
    }
    v.push_back(stoi(tmp));

    if (!isMinus) {
        for (auto& i : v) result += i;
    }
    else {
        for (int i = 0; i < midx; i++) result += v[i];
        for (int i = midx; i < v.size(); i++) result -= v[i];
    }

    cout << result;

    return 0;
}