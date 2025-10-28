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

using namespace std;

struct Point {
    long long x, y;
};

struct Line {
    Point p1, p2;
};

int groupCnt[3001];

void union_s(int a, int b, vector<int>& parent);
int find(int x, vector<int>& parent);
long long ccw(Point a, Point b, Point c);
bool isIntersect(Line A, Line B);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<Line> v(N + 1);
    vector<int> parent(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> v[i].p1.x >> v[i].p1.y >> v[i].p2.x >> v[i].p2.y;
        parent[i] = i;
        groupCnt[i] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (isIntersect(v[i], v[j])) union_s(i, j, parent);
        }
    }

    set<int> group;
    int maxGroup = 0;

    for (int i = 1; i <= N; i++) {
        int root = find(i, parent);
        group.insert(root);
        maxGroup = max(maxGroup, groupCnt[root]);
    }

    cout << group.size() << '\n' << maxGroup;
    return 0;
}

void union_s(int a, int b, vector<int>& parent) {
    a = find(a, parent);
    b = find(b, parent);
    if (a != b) {
        parent[b] = a;
        groupCnt[a] += groupCnt[b];
    }
    return;
}

int find(int x, vector<int>& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

long long ccw(Point a, Point b, Point c) {
    long long res = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (res > 0) return 1;
    if (res < 0) return -1;
    return 0;
}

bool isIntersect(Line A, Line B) {
    long long abc = ccw(A.p1, A.p2, B.p1);
    long long abd = ccw(A.p1, A.p2, B.p2);
    long long cda = ccw(B.p1, B.p2, A.p1);
    long long cdb = ccw(B.p1, B.p2, A.p2);

    if (abc * abd == 0 && cda * cdb == 0) {
        if (min(A.p1.x, A.p2.x) > max(B.p1.x, B.p2.x)) return false;
        if (min(B.p1.x, B.p2.x) > max(A.p1.x, A.p2.x)) return false;
        if (min(A.p1.y, A.p2.y) > max(B.p1.y, B.p2.y)) return false;
        if (min(B.p1.y, B.p2.y) > max(A.p1.y, A.p2.y)) return false;
        return true;
    }

    return (abc * abd <= 0 && cda * cdb <= 0);
}