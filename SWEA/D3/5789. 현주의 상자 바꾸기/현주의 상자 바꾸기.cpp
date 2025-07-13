#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <deque>

using namespace std;

int main() {
    int T = 0; cin >> T;
    for (int t = 1; t <= T; t++) {
        int N = 0, Q = 0;
        cin >> N >> Q;
        vector<int> boxes(N, 0);

        for (int i = 0; i < Q; i++) {
            int L = 0, R = 0;
            cin >> L >> R;

            for (int j = L; j <= R; j++) boxes[j - 1] = i + 1;
        }

        cout << "#" << t << " " ;
        for (int i = 0; i < N; i++) cout << boxes[i] << " ";
        cout << endl;
    }
    return 0;
}