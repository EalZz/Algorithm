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
    vector<int> v(T);
    for (int i = 0; i < T; i++) cin >> v[i];
    int N = 0; cin >> N;
    vector<int> v1(N);
    for (int i = 0; i < N; i++) cin >> v1[i];
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(T);
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    sort(v.begin(), v.end());
    
    
    for (auto& i : v1) {
        bool isFind = false;
        int start = 0, end = v.size() - 1, middle = end / 2;
        while (start <= end) {
            middle = (start + end) / 2;
            if (v[middle] == i) {
                isFind = true;
                break;
            }
            else if (v[middle] < i) start = middle + 1;
            else if (v[middle] > i) end = middle - 1;
        }

        if (!isFind) cout << 0;
        else cout << 1;
        cout << '\n';
    }

    return 0;
}