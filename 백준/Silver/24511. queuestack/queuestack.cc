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
    vector<int> qs(N);
    deque<int> defv;
    for (int i = 0; i < N; i++) cin >> qs[i];
    for (int i = 0; i < N; i++) {
        int tmp = 0; cin >> tmp;
        if (qs[i] == 0) defv.push_back(tmp);
    }

    int cnt = 0; cin >> cnt;

    for (int i = 0; i < cnt; i++) {
        int x = 0; cin >> x;

        defv.push_front(x);
        cout << defv.back() << " ";
        defv.pop_back();
    }
    
    return 0;
}