#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0; cin >> N;
    bool isthrow = true;
    queue<int> q;
    for (int i = 1; i <= N; i++) q.push(i);

    while (q.size() > 1) {
        if (isthrow) {
            q.pop();
            isthrow = false;
        }
        else {
            int tmp = q.front();
            q.pop();
            q.push(tmp);
            isthrow = true;
        }
    }
    cout << q.front();

    return 0;
}