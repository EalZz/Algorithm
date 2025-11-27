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

void bfs(int F, int S, int G, int U, int D, vector<bool> isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int F, S, G, U, D;
    cin >> F >> S >> G >> U >> D;

    vector<bool> isVisited(F + 1, false);

    bfs(F, S, G, U, D, isVisited);

    return 0;
}

void bfs(int F, int S, int G, int U, int D, vector<bool> isVisited) {
    queue<pair<int, int>> q;
    q.push({ S, 0 });
    isVisited[S] = true;

    while (!q.empty()) {
        int curLoca = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        if (curLoca == G) {
            cout << curLevel;
            return;
        }

        if (curLoca + U <= F && !isVisited[curLoca + U]) {
            q.push({ curLoca + U, curLevel + 1 });
            isVisited[curLoca + U] = true;
        }

        if (curLoca - D > 0 && !isVisited[curLoca - D]) {
            q.push({ curLoca - D, curLevel + 1 });
            isVisited[curLoca - D] = true;
        }
    }

    cout << "use the stairs";
    return;
}