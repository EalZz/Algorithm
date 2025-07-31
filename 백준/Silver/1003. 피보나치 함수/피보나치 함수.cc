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
int fibonacci(int n);

int memozation[40];
int cnt = 0;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N = 0, K = 0; 
    //cin >> N >> K;
    int T = 0; cin >> T;
    for (int i = 0; i < T; i++) {
        int test = 0; cin >> test;

        if (test == 0) cout << 1 << " " << 0;
        else cout << fibonacci(test - 1) << " " << fibonacci(test);
        cout << '\n';
    }

    return 0;
}

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    //계산한 값을 저장해서 메모리 효율 증가
    if (memozation[n] != 0) return memozation[n];
    memozation[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memozation[n];
}