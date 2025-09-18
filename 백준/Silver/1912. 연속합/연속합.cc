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
//int memo[21][21][21];
long long memo[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //memset(memo, -1, sizeof(memo));
    int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    vector<int> v(T);
    //vector<int> tmp;
    //vector<vector<int>> v(T, vector<int>(T));
    //vector<bool> isVisited(T, false);
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));
    int singleMax = -1e9;
    int sum = 0, sumMax = -1e9;

    for (int i = 0; i < T; i++) {
        cin >> v[i];
        singleMax = max(singleMax, v[i]);

        sum += v[i];
        sumMax = max(sum, sumMax);
        if (sum < 0) sum = 0;
    }

    int fmax = (singleMax < 0) ? singleMax : ((singleMax > sumMax) ? singleMax : sumMax);

    cout << fmax;

    return 0;
}
