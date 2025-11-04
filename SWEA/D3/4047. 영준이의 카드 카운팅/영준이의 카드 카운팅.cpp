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

        string str; cin >> str;

        int count[4];
        fill(count, count + 4, 13);
        vector<vector<bool>> isUsed(4, vector<bool>(14, false));
        bool isAble = true;
        for (int i = 0; i < str.size(); i += 3) {
            int diagram = 0;
            switch (str[i]) {
            case 'S': diagram = 0; break;
            case 'D': diagram = 1; break;
            case 'H': diagram = 2; break;
            case 'C': diagram = 3; break;
            }
            int num = stoi(str.substr(i + 1, 2));
            if (isUsed[diagram][num]) {
                isAble = false;
                break;
            }
            isUsed[diagram][num] = true;
            count[diagram]--;
        }

       
        cout << "#" << t << " ";
        if (isAble) {
            for (int i = 0; i < 4; i++) cout << count[i] << ' ';
        }
        else cout << "ERROR";
        cout << '\n';
    }
    return 0;
}