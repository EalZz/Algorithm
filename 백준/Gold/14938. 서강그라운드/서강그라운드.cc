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
//int memo[1001][3];
long long memo[10001];
//long long MOD = 1000000000;
//int memo[1000001][5][5];
//char starDr[10000][10000];

int dajikstra(int node, int b, vector<int>& gift, vector<vector<pair<int, int>>>& v);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N; cin >> N;
    //int M; cin >> M;
    int a = 0, b = 0, c = 0; cin >> a >> b >> c;

    vector<int> gift(a + 1);
    for (int i = 1; i <= a; i++) cin >> gift[i];

    vector<vector<pair<int, int>>> v(a + 1);
    for (int i = 0; i < c; i++) {
        int start, end, cost; cin >> start >> end >> cost;
        v[start].push_back({ end, cost });
        v[end].push_back({ start, cost });
    }

    int ans = 0;
    for (int i = 1; i <= a; i++) {
        fill(memo, memo + 10001, 1e9);
        ans = max(ans, dajikstra(i, b, gift, v));
    }

    cout << ans;

    return 0;
}

int dajikstra(int node, int b, vector<int>& gift, vector<vector<pair<int, int>>>& v) {
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, node });
    memo[node] = 0;

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        if (curCost > b) continue;
        if (curCost > memo[curNode]) continue;

        for (int i = 0; i < v[curNode].size(); i++) {
            int nextCost = curCost + v[curNode][i].second;
            int nextNode = v[curNode][i].first;

            if (nextCost < memo[nextNode]) {
                memo[nextNode] = nextCost;
                pq.push({ nextCost, nextNode });
            }
        }
    }

    int sum = 0;
    for (int i = 1; i < v.size(); i++) {
        if (memo[i] <= b) sum += gift[i];
    }
    return sum;
}