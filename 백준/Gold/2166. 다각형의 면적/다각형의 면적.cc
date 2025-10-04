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
#include <iomanip>

using namespace std;
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
long long memo[100001];
//int memo[101][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //queue<int> q;
    //vector<vector<int>>tree(T);
    //vector<vector<int>> v(T, vector<int>(N));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    
    vector<long long> x(T + 1), y(T + 1);
    double sum = 0.0;

    for (int i = 0; i < T; i++) cin >> x[i] >> y[i];
    x[T] = x[0];
    y[T] = y[0];
    
    for (int i = 0; i < T; i++) sum += ((x[i] * y[i + 1]) - (x[i + 1] * y[i]));

    double result = abs(sum) / 2.0;
    cout << fixed << setprecision(1) << result;

    return 0;
}
