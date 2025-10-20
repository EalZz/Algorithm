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
//int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> v1(N);
    for (int i = 0; i < N; i++) cin >> v1[i];

    int M; cin >> M;
    vector<int> v2(M);
    for (int i = 0; i < M; i++) cin >> v2[i];

    vector<int> tmp1 = v1, tmp2 = v2;
    sort(tmp1.begin(), tmp1.end(), greater<int>());
    sort(tmp2.begin(), tmp2.end(), greater<int>());

    vector<int> st;
    int idx1 = 0, idx2 = 0;
    while (idx1 < tmp1.size() && idx2 < tmp2.size()) {
        if (tmp1[idx1] == tmp2[idx2]) {
            int tidx1 = idx1 + 1, tidx2 = idx2 + 1, count1 = 1, count2 = 1;
            while (tidx1 < tmp1.size() && tmp1[tidx1] == tmp1[idx1]) {
                count1++;
                tidx1++;
            }
            while (tidx2 < tmp2.size() && tmp2[tidx2] == tmp2[idx2]) {
                count2++;
                tidx2++;
            }
            int count = min(count1, count2);
            for (int i = 0; i < count; i++) st.push_back(tmp1[idx1]);

            idx1 = tidx1;
            idx2 = tidx2;
        }
        else if (tmp1[idx1] > tmp2[idx2]) idx1++;
        else idx2++;
    }

    if (st.size() == 0) {
        cout << 0;
        return 0;
    }

    vector<int> result;
    int idx = 0;
    idx1 = -1, idx2 = -1;
    while (idx < st.size()) {
        auto it1 = find(v1.begin() + idx1 + 1, v1.end(), st[idx]);
        auto it2 = find(v2.begin() + idx2 + 1, v2.end(), st[idx]);

        if (it1 == v1.end() || it2 == v2.end()) {
            idx++;
            continue;
        }

        int stidx1 = it1 - v1.begin();
        int stidx2 = it2 - v2.begin();

        result.push_back(v1[stidx1]);
        idx1 = stidx1;
        idx2 = stidx2;
        idx++;
    }

    cout << result.size() << '\n';
    for (auto& i : result) cout << i << ' ';

    return 0;
}