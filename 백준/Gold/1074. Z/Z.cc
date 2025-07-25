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
int Z(int N, int r, int c);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0, r = 0, c = 0;
    cin >> N >> r >> c;

    cout << Z(N, r, c);

    return 0;
}

int Z(int N, int r, int c) {
    if (N == 0) return 0;

    int half = pow(2, N - 1);
    int size = half * half;

    if (r < half && c < half) return Z(N - 1, r, c);
    else if (r < half && c >= half) return size + Z(N - 1, r, c - half);
    else if (r >= half && c < half) return size * 2 + Z(N - 1, r - half, c);
    else if (r >= half && c >= half) return size * 3 + Z(N - 1, r - half, c - half);
}