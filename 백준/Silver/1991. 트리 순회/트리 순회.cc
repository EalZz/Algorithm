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
void preorder(char node, map<char, vector<char>>& tree);
void  postorder(char node, map<char, vector<char>>& tree);
void  inorder(char node, map<char, vector<char>>& tree);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<char, vector<char>> tree;
    //map<char, bool> isVisited;

    int N = 0; cin >> N;
    for (int i = 0; i < N; i++) {
        char root, left, right; 
        cin >> root >> left >> right;
        tree[root] = { left, right };
        //isVisited[root] = false;
    }

    preorder('A', tree); cout << '\n';
    postorder('A', tree); cout << '\n';
    inorder('A', tree);

    return 0;
}

void preorder(char node, map<char, vector<char>>& tree) {
    if (node == '.') return;     

    cout << node;                 
    preorder(tree[node][0], tree);  
    preorder(tree[node][1], tree); 
}


void  postorder(char node, map<char, vector<char>>& tree) {
    if (node == '.') return;

    postorder(tree[node][0], tree);
    cout << node;
    postorder(tree[node][1], tree);
}

void  inorder(char node, map<char, vector<char>>& tree) {
    if (node == '.') return;

    inorder(tree[node][0], tree);
    inorder(tree[node][1], tree);
    cout << node;
}

/*
void  preorder(char idx, map<char, vector<char>> tree, map<char, bool>& isVisited) {
    if (isVisited[idx] == false) {
        cout << idx;
        isVisited[idx] = true;
        if (!isVisited[tree[idx][0]] && tree[idx][0] != '.')
            preorder(tree[idx][0], tree, isVisited);
        else if (!isVisited[tree[idx][1]] && tree[idx][1] != '.')
            preorder(tree[idx][1], tree, isVisited);
        else return;
    }
    if (!isVisited[tree[idx][0]] && tree[idx][0] != '.')
        preorder(tree[idx][0], tree, isVisited);
    else if (!isVisited[tree[idx][1]] && tree[idx][1] != '.')
        preorder(tree[idx][1], tree, isVisited);
    else return;
}
*/