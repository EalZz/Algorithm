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
//int memo[21][21][21];
int memo[10000001];

void combi(int T, int N, vector<int>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(memo, -1, sizeof(memo));

    int T = 0; cin >> T;
    int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0;
    vector<int> v;
    vector<bool> isVisited(T + 1, false);

    combi(T, N, v, isVisited);

    return 0;
}

void combi(int T, int N, vector<int>& v, vector<bool>& isVisited) {
    if (v.size() == N) {
        for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= T; i++) {
        if (!isVisited[i]) {
            isVisited[i] = true;
            v.push_back(i);

            combi(T, N, v, isVisited);

            isVisited[i] = false;
            v.pop_back();
        }
    }
    return;
}