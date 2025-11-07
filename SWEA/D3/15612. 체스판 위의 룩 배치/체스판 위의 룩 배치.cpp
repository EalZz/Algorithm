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
        vector<bool> Vcol(8, false);

        bool isAble = true;
        int cnt = 0;
        for (int row = 0; row < 8; row++) {
            string tmp; cin >> tmp;
            bool Vrow = false;
            for (int col = 0; col < 8; col++) {
                if (tmp[col] == 'O') {
                    cnt++;
                    if (Vrow || Vcol[col]) {
                        isAble = false;
                        //break;
                    }
                    Vrow = true;
                    Vcol[col] = true;
                }
            }
            //if (!isAble) break;
        }

        cout << "#" << t << " ";
        if (isAble && cnt == 8) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
    return 0;
}