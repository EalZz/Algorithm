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

        int N; cin >> N;
        vector<string> v(N);
        vector<string> cv(N);
        for (int row = 0; row < N; row++) {
            cin >> v[row];
            for (int col = 0; col < N; col++) cv[col].push_back(v[row][col]);
        }

        bool isAble = false;
        for (int row = 0; row < N; row++) {
            if (v[row].find("ooooo") == string::npos && 
                cv[row].find("ooooo") == string::npos) continue;
            isAble = true;
            break;
        }

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < N; col++) {
                if (isAble) break;
                if (v[row][col] != 'o') continue;

                int nrow = row;
                int ncol = col;
                int cnt = 1;
                while (nrow < N && ncol < N) {
                    nrow++;
                    ncol++;
                    if (nrow >= N || ncol < 0) break;
                    if (v[nrow][ncol] != 'o') break;
                    cnt++;
                }
                if (cnt >= 5) {
                    isAble = true;
                    break;
                }
            }
            if (isAble) break;
        }

        for (int row = 0; row < N; row++) {
            for (int col = N - 1; col >= 0; col--) {
                if (isAble) break;
                if (v[row][col] != 'o') continue;

                int nrow = row;
                int ncol = col;
                int cnt = 1;
                while (1) {
                    nrow++;
                    ncol--;
                    if (nrow >= N || ncol < 0) break;
                    if (v[nrow][ncol] != 'o') break;
                    cnt++;
                }
                if (cnt >= 5) {
                    isAble = true;
                    break;
                }
            }
            if (isAble) break;
        }

        cout << "#" << t << " ";
        if (isAble) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}
