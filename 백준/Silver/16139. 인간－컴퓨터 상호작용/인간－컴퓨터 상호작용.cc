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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));
    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T + 1, 0);
    //vector<int> tmp;
    //vector<vector<int>> v(T + 1, vector<int>(T + 1, 0));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    
    string tmp; cin >> tmp;
    vector<vector<int>> alphaidx(26, vector<int>(tmp.size() + 1, 0));
    for (int row = 1; row <= tmp.size(); row++) {
        for (int j = 0; j < 26; j++)  alphaidx[j][row] = alphaidx[j][row - 1];
        alphaidx[tmp[row - 1] - 97][row]++;
    }

    int t; cin >> t;
    while (t--) {
        char falpha; cin >> falpha;
        int start, end;
        cin >> start >> end;

        cout << alphaidx[falpha - 97][end + 1] - alphaidx[falpha - 97][start] << '\n';
    }

    return 0;
}