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
//int qmatrix(vector<vector<int>>& matrix, int row, int col, int T);
string star(string s, int T, int black);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N = 0, K = 0; 
    //cin >> N >> K;
    int T = 0; cin >> T;
    string s;

    cout << star(s, T, 0);

    return 0;
}

string star(string s, int T, int black) {
    if (T == 0) return s;

    s += string(black, ' ');
    s += string(T, '*');
    s += '\n';

    return star(s, T - 1, black + 1);
}


int qmatrix(vector<vector<int>>& matrix, int row, int col, int T) {
    return 0;
}