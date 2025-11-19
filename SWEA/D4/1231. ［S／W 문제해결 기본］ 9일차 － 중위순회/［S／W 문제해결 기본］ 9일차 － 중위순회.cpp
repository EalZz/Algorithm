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

void dfs(int node, vector<char>& value, vector<vector<int>>& edge);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T = 10; //cin >> T;

    for (int t = 1; t <= T; t++) {
        //int tc; cin >> tc;

        int N; cin >> N; cin.ignore();
        vector<char> value(N + 1);
        vector<vector<int>> edge(N + 1, vector<int>(2, -1));
        while (N--) {
            string s; getline(cin, s);
            vector<string> sv;
            string tmp = "";
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                    sv.push_back(tmp);
                    tmp = "";
                    continue;
                }

                tmp += s[i];
            }
            if(tmp != "") sv.push_back(tmp);

            int node = stoi(sv[0]);
            value[node] = sv[1][0];
            if (sv.size() >= 3) edge[node][0] = stoi(sv[2]);
            if (sv.size() >= 4) edge[node][1] = stoi(sv[3]);
        }


        cout << "#" << t << " ";
        dfs(1, value, edge);
        cout << '\n';
    }
    return 0;
}

void dfs(int node, vector<char>& value, vector<vector<int>>& edge) {
    if (node == -1) return;

    dfs(edge[node][0], value, edge);
    cout << value[node];
    dfs(edge[node][1], value, edge);

    return;
}