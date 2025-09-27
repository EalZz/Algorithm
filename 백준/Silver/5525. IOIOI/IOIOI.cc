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
    //vector<vector<int>> v(T + 1);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string s; cin >> s;
    int IOIcnt = 0;

    for (int i = 1; i < N - 1; i++) {
        if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
            IOIcnt++;
            if (IOIcnt >= T) cnt++;
            i++;
        }
        else IOIcnt = 0;
    }
    cout << cnt;

    return 0;
}
