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

    string s; cin >> s;
    sort(s.begin(), s.end());
    vector<int> v(26, 0), one;

    for (auto& c : s) v[c - 'A']++;
    
    int cnt = 0, mid = -1;
    for (int i = 0; i < 26; i++) {
        if (v[i] % 2 == 1) {
            cnt++;
            mid = i;
        }
        if (cnt > 1) {
            cout << "I'm Sorry Hansoo";
            return 0;
        }
        
        v[i] /= 2;
    }

    string ans, tmp;
    for (int i = 0; i < 26; i++) {
        if (v[i] == 0) continue;
        for (int j = 0; j < v[i]; j++) tmp.push_back(i + 'A');
    }
    ans = tmp;
    if (mid != -1) ans += (mid + 'A');
    for (int i = tmp.size() - 1; i >= 0; i--) ans.push_back(tmp[i]);

    cout << ans;

    return 0;
}
