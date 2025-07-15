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
    int insertN = 0;
    stack<int> s;

    for (int i = 0; i < N; i++) {
        int cmd = 0; cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> insertN;
            s.push(insertN);
            break;
        case 2:
            if (s.size() > 0) {
                cout << s.top() << '\n';
                s.pop();
            }
            else cout << "-1" << '\n';
            break;
        case 3:
            cout << s.size() << '\n';
            break;
        case 4:
            if (s.empty()) cout << "1" << '\n';
            else cout << "0" << '\n';
            break;
        case 5:
            if (s.size() > 0) cout << s.top() << '\n';
            else cout << "-1" << '\n';
            break;
        }
        cmd = 0;
        insertN = 0;
    }

    return 0;
}
