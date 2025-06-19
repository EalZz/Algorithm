#include<iostream>
#include<vector>
#include <cmath>

using namespace std;
void btprint(int k, vector<int> v);

int main() {
    int T = 0;
    cin >> T;
    cin.ignore();

    for (int i = 1; i <= T; i++) {
        int k = 0;
        vector<int> v; 
        cin >> k;
        for (int j = 0; j < pow(2, k) - 1; j++) {
            int tmp = 0;
            cin >> tmp;
            v.push_back(tmp);
        }

        cout << "#" << i << " ";
        btprint(k, v);
    }
    return 0;
}

void btprint(int k, vector<int> v) {
    for (int level = 0; level < k; level++) {
        int start = pow(2, k - level - 1) - 1;
        int step = pow(2, k - level);
        int count = pow(2, level);
        for (int i = 0; i < count; i++) {
            int idx = start + i * step;
            cout << v[idx] << " ";
        }
        cout << "\n";
    }
}