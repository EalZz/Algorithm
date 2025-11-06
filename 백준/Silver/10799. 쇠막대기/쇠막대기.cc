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

void bfs(int row, int col, vector<vector<int>>& v, vector<vector<bool>>& isSink);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string pipe; cin >> pipe;
   
    stack<char> s;
    int ans = 0;

    for (int i = 0; i < pipe.size(); i++) {
        if (pipe[i] == '(') s.push('(');
        else {
            s.pop();
            if (pipe[i - 1] == '(') ans += s.size();
            else ans += 1;
        }
    }

    cout << ans;

    return 0;
}