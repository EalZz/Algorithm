#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{   
    int T = 0; cin >> T;
    set<string> check;
    check.insert("ChongChong");

    for (int i = 0; i < T; i++) {
        string tmp1, tmp2;
        cin >> tmp1 >> tmp2;

        if (check.find(tmp1) != check.end() || check.find(tmp2) != check.end()) {
            check.insert(tmp1);
            check.insert(tmp2);
        }
    }
    cout << check.size();

    return 0;
}
