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
#include <memory>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int M;
    cin >> s >> M;

    list<char> l(s.begin(), s.end()); 
    auto it = l.end();

    while (M--) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
        case 'L':
            if (it != l.begin()) it--;
            break;
        case 'D':
            if (it != l.end()) it++;
            break;
        case 'B':
            if (it != l.begin()) it = l.erase(--it);
            break;
        case 'P': 
            char c;
            cin >> c;
            l.insert(it, c);
            break;
        }
    }

    for (char c : l) cout << c;

    return 0;
}