#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<deque>

using namespace std;

int main() {
    int T = 0;
    cin >> T;
    cin.ignore();

    map<string, int> m = {
         {"ZRO", 0}, {"ONE", 1}, {"TWO", 2}, {"THR", 3}, {"FOR", 4},
         {"FIV", 5}, {"SIX", 6}, {"SVN", 7}, {"EGT", 8}, {"NIN", 9}
    };

    map<int, string> rm = {
        {0, "ZRO"}, {1, "ONE"}, {2, "TWO"}, {3, "THR"}, {4, "FOR"},
        {5, "FIV"}, {6, "SIX"}, {7, "SVN"}, {8, "EGT"}, {9, "NIN"}
    };

    for (int i = 1; i <= T; i++) {
        string s;
        int len = 0;
        cin >> s >> len;

        vector<int> num;

        for (int j = 0; j < len; j++) {
            string tmp;
            cin >> tmp;
            num.push_back(m[tmp]);
        }
        sort(num.begin(), num.end());
        cout << "#" << i << " " << endl;
        for (int j = 0; j < len; j++) {
            int tmp = num[j];
            cout << (rm[tmp]) << " ";
        }
        cout << endl;
    }
    return 0;
}
