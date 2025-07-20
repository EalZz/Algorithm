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
void star(long long T, long long row, long long col);

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long T = 0; cin >> T;
    long long row = T, col = T;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            star(T, i, j);
        }
        cout << '\n';
    }
    return 0;
}

void star(long long T, long long row, long long col) {
    if (T == 1) {
        cout << "*";
        return;
    }
    long long token = T / 3;
    long long trow = row / token;
    long long tcol = col / token;
    
    if (trow == 1 && tcol == 1) cout << " ";
    else star(token, row % token, col % token);
}