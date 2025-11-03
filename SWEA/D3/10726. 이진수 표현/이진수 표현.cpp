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

        int N, M; cin >> N >> M;

        int cnt = 0;
        bool isAble = true;
        while (M / 2 >= 0 && cnt < N) {
            if (M % 2 == 0) {
                isAble = false;
                break;
            }

            M /= 2;
            cnt++;
        }
       
        cout << "#" << t << " ";
        if (isAble) cout << "ON";
        else cout << "OFF";
        cout << '\n';
    }
    return 0;
}