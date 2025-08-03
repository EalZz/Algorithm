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
void preorder(map<char, vector<char>>& tree, char node);
void inorder(map<char, vector<char>>& tree, char node);
void postorder(map<char, vector<char>>& tree, char node);


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int N = 0, K = 0; 
    //cin >> N >> K;
    int T = 0; cin >> T;
    
    map<char, vector<char>> tree;

    for (int i = 0; i < T; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root] = { left, right };
    }

    preorder(tree, 'A'); cout << '\n';
    inorder(tree, 'A'); cout << '\n';
    postorder(tree, 'A');

    return 0;
}

void preorder(map<char, vector<char>>& tree, char node) {
    if (node == '.') return;

    cout << node;
    preorder(tree, tree[node][0]);
    preorder(tree, tree[node][1]);

    return;
}

void inorder(map<char, vector<char>>& tree, char node) {
    if (node == '.') return;

    inorder(tree, tree[node][0]);
    cout << node;
    inorder(tree, tree[node][1]);

    return;
}

void postorder(map<char, vector<char>>& tree, char node) {
    if (node == '.') return;

    postorder(tree, tree[node][0]);
    postorder(tree, tree[node][1]);
    cout << node;

    return;
}

int qmatrix(vector<vector<int>>& matrix, int row, int col, int T) {
    return 0;
}