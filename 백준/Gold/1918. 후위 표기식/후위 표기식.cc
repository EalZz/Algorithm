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
int cnt = 0, cnt1 = 0;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//long long memo[3];
//int memo[101][4];
long long memo[10001];

void dfs(int node, int sum, vector<vector<pair<int, int>>>& v, vector<bool>& isVisited);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int T = 0; cin >> T;
    //int N = 0; cin >> N;
    //int a = 0, b = 0, c = 0; cin >> a >> b >> c;
    //vector<int> v(N + 1, 0);
    //vector<vector<int>> v(T);
    //vector<bool> isVisited(T + 1, false);
    //vector<vector<bool>> isVisited(T, vector<bool>(N, false));
    //vector<vector<int>> matrix(b, vector<int>(a, 0));
    //vector<vector<bool>> isVisited(T, vector<bool>(T, false));

    string str, result = ""; cin >> str;
    stack<char> st;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') result.push_back(str[i]);
        else if (str[i] == '*' || str[i] == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/')) {
                result.push_back(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
        else if (str[i] == '+' || str[i] == '-') {
            while (!st.empty() && st.top() != '(') {
                result.push_back(st.top());
                st.pop();
            }
            st.push(str[i]);
        }
        else if (str[i] == '(') st.push(str[i]);
        else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                result.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
    }
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    cout << result;

    return 0;
}
