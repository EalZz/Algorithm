#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>

using namespace std;
bool isSubset(vector<int> a, vector<int> b);

int main() {
    int T = 0; cin >> T;
    for (int i = 1; i <= T; i++) {
        int asize = 0, bsize = 0;
        cin >> asize >> bsize;

        vector<int> a, b;
        for (int j = 0; j < asize; j++) {
            int tmp = 0;
            cin >> tmp;
            a.push_back(tmp);
        }
        for (int j = 0; j < bsize; j++) {
            int tmp = 0;
            cin >> tmp;
            b.push_back(tmp);
        }

        if (asize == bsize) {
            if (isSubset(a, b)) cout << "=";
        }
        else if (asize < bsize) {
            if (isSubset(a, b)) cout << "<";
        }
        else {
            if (isSubset(b, a)) cout << ">";
        }

        cout << endl;
        //cout << "#" << i << " ";
    }
    return 0;
}

bool isSubset(vector<int> a, vector<int> b) {
    for (int j = 0; j < a.size(); j++) {
        if (find(b.begin(), b.end(), a[j]) == b.end()) {
            cout << "?";
            return false;
        }
    }
    return true;
}