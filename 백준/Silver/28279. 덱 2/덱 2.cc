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
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    int insertN = 0;
    deque<int> d;

    for (int i = 0; i < N; i++) {
        int cmd = 0; cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> insertN;
            d.push_front(insertN);
            break;
        case 2:
            cin >> insertN;
            d.push_back(insertN);
            break;
        case 3:
            if (d.size() > 0) {
                cout << d.front() << '\n';
                d.pop_front();
            }
            else cout << "-1" << '\n';
            break;
        case 4:
            if (d.size() > 0) {
                cout << d.back() << '\n';
                d.pop_back();
            }
            else cout << "-1" << '\n';
            break;
        case 5:
            cout << d.size() << '\n';
            break;
        case 6:
            if (d.empty()) cout << "1" << '\n';
            else cout << "0" << '\n';
            break;
        case 7:
            if (d.size() > 0) cout << d.front() << '\n';
            else cout << "-1" << '\n';
            break;
        case 8:
            if (d.size() > 0) cout << d.back() << '\n';
            else cout << "-1" << '\n';
            break;
        }
        cmd = 0;
        insertN = 0;
    }

    return 0;
}