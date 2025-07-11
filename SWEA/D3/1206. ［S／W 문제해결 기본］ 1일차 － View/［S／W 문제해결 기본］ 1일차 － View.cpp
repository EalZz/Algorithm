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
    int T = 10; //cin >> T;
    for (int i = 1; i <= T; i++) {
        vector<int> apt;
        int cnt = 0; cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int tmp = 0; cin >> tmp;
            apt.push_back(tmp);
        }

        cout << "#" << i << " ";
        if (cnt == 4) {
            cout << "0" << endl;
            break;
        }

        int count = 0;
        deque<int> view;

        for (int j = 0; j < 5; j++) view.push_back(apt[j]);
        for (int j = 2; j < cnt - 2; j++) {
            bool isView = true;
            int max = 0;

            for (int k = 0; k < 5; k++) {
                if (k == 2) continue;
                if (view[k] >= view[2]) {
                    isView = false;
                    break;
                }
                max = (view[k] > max) ? view[k] : max;
            }
            if (isView) count += view[2] - max;

            if (j != cnt - 3) {
                view.pop_front();
                view.push_back(apt[j + 3]);
            }
        }
        cout << count << endl;
    }
    return 0;
}