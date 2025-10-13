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
int memo[1001][3];
//long long memo[100001];
//long long MOD = 1000000000;

int find(int i, vector<int>& p);
void union_s(int a, int b, vector<int>& p);
bool isSameP(int a, int b, vector<int>& p);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    int M = 0; cin >> M;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<long long> v(T + 1, 0);
    vector<vector<int>> v(N);
    //vector<bool> isVisited(a + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    int result = 0;
    vector<int> p(N);
    for (int i = 0; i < N; i++) p[i] = i;

    for (int i = 1; i <= M; i++) {
        int tmp1, tmp2; cin >> tmp1 >> tmp2;
        if (isSameP(tmp1, tmp2, p)) {
            result = i;
            break;
        }
        
        union_s(tmp1, tmp2, p);
    }

    cout << result;

    return 0;
}

int find(int i, vector<int>& p) {
    if (p[i] == i) return i;
    return p[i] = find(p[i], p);
}

void union_s(int a, int b, vector<int>& p) {
    a = find(a, p);
    b = find(b, p);
    if (a != b) p[b] = a;
    return;
}

bool isSameP(int a, int b, vector<int>& p) {
    a = find(a, p);
    b = find(b, p);
    if (a == b) return true;
    return false;
}