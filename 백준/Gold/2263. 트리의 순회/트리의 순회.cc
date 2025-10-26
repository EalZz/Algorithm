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
int cnt = 0, cnt1 = 1e9;
//int cnt_1 = 0, cnt0 = 0, cnt1 = 0;
//int memo[21][21][21];
//int memo[1001][3];
//long long memo[501][501];
//long long MOD = 1000000007;
//int memo[1000001][5][5];

void preorder(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder, vector<int>& idx);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;

    vector<int> inorder(N + 1, -1), postorder(N + 1, -1), idx(N + 1, -1);
    
    for (int i = 1; i <= N; i++) {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }
    for (int i = 1; i <= N; i++) cin >> postorder[i];

    preorder(1, N, 1, N, inorder, postorder, idx);

    return 0;
}

void preorder(int inStart, int inEnd, int postStart, int postEnd, vector<int>& inorder, vector<int>& postorder, vector<int>& idx) {
    if (inStart > inEnd || postStart > postEnd) return;

    int rootidx = idx[postorder[postEnd]];
    cout << inorder[rootidx] << ' ';

    int left = rootidx - inStart;
    int right = inEnd - rootidx;
    preorder(inStart, rootidx - 1, postStart, postStart + left - 1, inorder, postorder, idx);
    preorder(rootidx + 1, inEnd, postStart + left, postEnd - 1, inorder, postorder, idx);
}
