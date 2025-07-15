#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>

using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    int insertN = 0, sum = 0;
    stack<int> s;

    for (int i = 0; i < N; i++) {
        int cmd = 0; cin >> cmd;
        switch (cmd)
        {
        case 0:
            if (s.size() > 0) s.pop();
            break;
        default:
            s.push(cmd);
        }
        cmd = 0;
        insertN = 0;
    }

    int len = s.size();
    for (int i = 0; i < len; i++) {
        sum += s.top();
        s.pop();
    }
    cout << sum;

    return 0;
}
