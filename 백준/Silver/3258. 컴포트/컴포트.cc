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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Z, M; cin >> N >> Z >> M;

    bool ob[1001];
    fill(ob, ob + 1001, true);
    for (int i = 0; i < M; i++) {
        int tmp; cin >> tmp;
        ob[tmp] = false;
    }
    vector<bool> isVisited(N + 1, false);
    isVisited[0] = true;

    int ans = 0;
    for (int i = 1; i < N; i++) {
        int cur = 1;
        vector<bool> isVisited(N + 1, false);
        isVisited[0] = isVisited[cur] = true;
        bool isAble = true;

        while (1) {
            cur += i;
            if (cur > N) cur -= N;

            if (!ob[cur] || isVisited[cur]) {
                isAble = false;
                break;
            }

            if (cur == Z) {
                ans = i;
                break;
            }

            isVisited[cur] = true;
        }
        if (isAble) break;
    }

    cout << ans;

    return 0;
}