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
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    vector<pair<string, pair<int, int>>> v(N);
    for (int i = 0; i < N; i++) {
        string tmp; cin >> tmp;
        int sum = 0;
        for (auto& t : tmp) {
            if (!isdigit(t)) continue;
            sum += (t - '0');
        }
        v[i] = { tmp, {tmp.length(), sum} };
    }

    sort(v.begin(), v.end(), [](pair<string, pair<int, int>> a, pair<string, pair<int, int>> b) {
        if (a.second.first != b.second.first) return a.second.first < b.second.first; 
        if (a.second.second != b.second.second) return a.second.second < b.second.second; 
        return a.first < b.first; 
    });

    for (auto i : v)  cout << i.first << '\n';

    return 0;
}