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
//long long memo[3];
long long memo[101][10001];
//long long memo[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    while (T--) {
        int a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 1 << '\n';
            continue;
        }
        if (b == 1) {
            cout << b << '\n';
            continue;
        }

        long long result = 1;
        int k = 1;
        for (int i = b; i > b - a; i--) {
            result *= i;
            result /= k;
            k++;
        }
        cout << result << '\n';
    }


    return 0;
}