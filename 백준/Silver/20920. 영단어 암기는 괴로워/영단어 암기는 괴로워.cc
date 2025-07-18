#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 0; cin >> T;
    int M = 0; cin >> M;
    map<string, int> vocab;

    for (int i = 0; i < T; i++) {
        string tmp; cin >> tmp;
        if (tmp.size() < M) continue;
        vocab[tmp]++;
    }
    vector<pair<string, int>> vocabv(vocab.begin(), vocab.end());

    sort(vocabv.begin(), vocabv.end(), [](pair<string, int> a, pair<string, int> b) {
        if (a.second != b.second) return a.second > b.second;
        if (a.first.size() != b.first.size()) return a.first.length() > b.first.length();
        return a.first < b.first;
        });

    for (auto v : vocabv) cout << v.first << '\n';

    return 0;
}
