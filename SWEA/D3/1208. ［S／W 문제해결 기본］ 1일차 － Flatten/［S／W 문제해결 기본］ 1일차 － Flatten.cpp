#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int T = 0; //cin >> T;
    T = 10;
    for (int i = 1; i <= T; i++) {
        int dump = 0; cin >> dump;

        vector<int> boxes;
        for (int j = 0; j < 100; j++) {
            int tmp = 0; cin >> tmp;
            boxes.push_back(tmp);
        }

        while (dump--) {
            sort(boxes.begin(), boxes.end());
            boxes[0]++; boxes[99]--;
        }
        sort(boxes.begin(), boxes.end());

        cout << "#" << i << " " << boxes[99] - boxes[0] << endl;
    }
    return 0;
}