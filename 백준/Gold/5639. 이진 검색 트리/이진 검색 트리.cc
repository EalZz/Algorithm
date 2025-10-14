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
//int memo[1001][3];
//long long memo[1000001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

void post(int start, int end, vector<int>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N; cin >> N;
    //int M; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v;
    //vector<vector<int>> v(N);
    //vector<bool> isVisited(4000001, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    int tmp;
    while (cin >> tmp) v.push_back(tmp);

    post(0, v.size(), v);

    return 0;
}

void post(int start, int end, vector<int>& v) {
    if (start >= end) return;

    int root = v[start];

    int rstart = end;
    for (int i = start + 1; i < end; i++) {
        if (root < v[i]) {
            rstart = i;
            break;
        }
    }
    post(start + 1, rstart, v);
    post(rstart, end, v);

    cout << root << '\n';
}
