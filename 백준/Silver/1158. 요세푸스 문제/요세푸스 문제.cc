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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, K; cin >> N >> K;
    vector<int> v;
    vector<bool> isVisited(N + 1, false);
    isVisited[0] = true;

    int num = 0;
    while (v.size() != N) {
        int cnt = K;
        while (cnt--) {
            num++;
            while (1) {
                if (num > N) {
                    num = 1;
                    continue;
                }
                if (isVisited[num]) {
                    num++;
                    continue;
                }
                break;
            }
        }
        v.push_back(num);
        isVisited[num] = true;
    }
    
    cout << '<'; 
    for (int i = 0; i < N - 1; i++) cout << v[i] << ", ";
    cout << v[N - 1] << '>';

    return 0;
}