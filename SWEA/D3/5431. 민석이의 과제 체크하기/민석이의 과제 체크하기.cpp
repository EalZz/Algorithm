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

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int N, K; cin >> N >> K;

        vector<int>isVisited(N + 1, false);
        for (int i = 0; i < K; i++) {
            int tmp; cin >> tmp;
            isVisited[tmp] = true;
        }
       
        cout << "#" << t << " ";
        for (int i = 1; i <= N; i++) {
            if (!isVisited[i]) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}