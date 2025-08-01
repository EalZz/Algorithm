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
void star(int N, int row, int col);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N = 0, K = 0; 
    //cin >> N >> K;
    int T = 0; cin >> T;

    for (int i = 0; i < T; i++) {
        for (int j = 0; j < T; j++) star(T, i, j);
        cout << '\n';
    }

    return 0;
}

void star(int N, int row, int col) {
    if (N == 1) {
        cout << "*";
        return;
    }

    int size = N / 3;
    int trow = row / size;
    int tcol = col / size;

    if (trow == 1 && tcol == 1) {
        cout << " ";
        return;
    }

    star(size, row % size, col % size);
}