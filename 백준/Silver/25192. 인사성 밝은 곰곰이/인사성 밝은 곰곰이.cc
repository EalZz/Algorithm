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
    int cnt = 0;
    set<string> check;

    for (int i = 0; i < T; i++) {
        string tmp; cin >> tmp;
        if (tmp == "ENTER") {
            cnt += check.size();
            check.clear();
            continue;
        }
        check.insert(tmp);
    }
    cnt += check.size();
    cout << cnt;

    return 0;
}
