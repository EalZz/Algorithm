#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    for (int i = 1; i <= 10; i++) {
        int N = 0; cin >> N;
        vector<int> v;

        for (int j = 0; j < N; j++) {
            int tmp = 0;
            cin >> tmp;
            v.push_back(tmp);
        }
        
        int M = 0; cin >> M;

        for (int j = 0; j < M; j++) {
            char order; cin >> order;
            int x = 0, y = 0, c = 0;
            vector<int> tmp;

            switch (order)
            {
            case 'I':
                cin >> x >> y;
                for (int k = 0; k < y; k++) {
                    int c = 0; cin >> c;
                    tmp.push_back(c);
                }
                v.insert(v.begin() + x, tmp.begin(), tmp.end());
                break;
            case 'D':
                cin >> x >> y;
                for (int k = 0; k < y; k++) v.erase(v.begin() + x);
                break;
            case 'A' :
                cin >> y;
                for (int k = 0; k < y; k++) {
                    cin >> c;
                    v.push_back(c);
                }
                break;
            }
        }

        cout << "#" << i << ' ';
        for (int j = 0; j < 10; j++) cout << v[j] << ' ';
        cout << endl;
    }
    return 0;
}