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
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];
long long memo[10001];

int find(int x, vector<int>& p);
void union_s(int a, int b, vector<int>& p);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T);
    //vector<vector<int>> v(N + 1);
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];

    int left = 0, right = T - 1, lv = 0, rv = 0, minValue = 2 * 1e9;

    while (left < right) {
        int sum = v[left] + v[right];
        if (minValue > abs(sum)) {
            minValue = abs(sum);
            lv = v[left];
            rv = v[right];
        }
        if (sum < 0) left++;
        else if (sum > 0) right--;
        else break;
    }

    cout << lv << ' ' << rv;

    return 0;
}
