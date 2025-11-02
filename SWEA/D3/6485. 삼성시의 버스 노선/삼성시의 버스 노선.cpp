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

        vector<int> bus(5002, 0);

        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            int A, B; cin >> A >> B;
            bus[A]++;
            bus[B + 1]--;
        }

        for (int i = 1; i <= 5000; i++) bus[i] += bus[i - 1];

        int P; cin >> P;
        cout << '#' << t << ' ';
        while (P--) {
            int C; cin >> C;
            cout << bus[C] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
