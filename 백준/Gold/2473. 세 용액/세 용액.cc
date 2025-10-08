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
//long long memo[101][10];
long long memo[100001];
//long long MOD = 1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<long long> v(T, 0);
    //vector<vector<int>> v(N , vector<int>(2));
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    for (int i = 0; i < T; i++) cin >> v[i];
    sort(v.begin(), v.end());

    long long result = 3 * 1e9;
    long long iv = 0, lv = 0, rv = 0;

    for (int i = 0; i < T - 2; i++) {
        int left = i + 1, right = T - 1;
        
        while (left < right) {
            long long sum = v[i] + v[left] + v[right];
            if (result > abs(sum)) {
                result = abs(sum);
                iv = v[i];
                lv = v[left];
                rv = v[right];
            }

            if (sum > 0) right--;
            else if (sum < 0) left++;
            else break;
        }
    }

    cout << iv << ' ' << lv << ' ' << rv;

    return 0;
}
