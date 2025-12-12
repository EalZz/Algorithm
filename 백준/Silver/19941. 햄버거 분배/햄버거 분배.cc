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

int main() {
    string s;
    int N, K, cnt = 0;
    cin >> N >> K >> s;

    for (int i = 0; i < N; i++) {
        if (s[i] != 'P') continue;

        for (int j = i - K; j <= i + K; j++) {
            if (0 <= j && j < N && s[j] == 'H') {
                s[j] = '-';
                cnt++;
                break;
            }
        }
    }

    cout << cnt;
}
