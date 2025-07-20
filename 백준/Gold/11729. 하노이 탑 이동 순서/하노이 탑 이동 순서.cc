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

using namespace std;
int hanoi(int T);
void hcnt(int T, int from, int to, int mid);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    cout << hanoi(T) << '\n';
    hcnt(T, 1, 3, 2);

    return 0;
}

int hanoi(int T) {
    if (T == 1) return 1;
    int cnt = hanoi(T - 1) * 2 + 1;
    return cnt;
}

void hcnt(int T, int from, int to, int mid) {
    if (T == 1) {
        cout << from << " " << to << '\n';
        return;
    }

    hcnt(T - 1, from, mid, to);
    cout << from << " " << to << '\n';
    hcnt(T - 1, mid, to, from);
}