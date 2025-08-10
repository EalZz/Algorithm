#include <string>
#include <vector>

using namespace std;

void dfs(int node, vector<vector<int>>& computers, vector<bool>& isVisited);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isVisited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(!isVisited[i]) {
            answer++;
            dfs(i, computers, isVisited);
        }
    }
    return answer;
}

void dfs(int node, vector<vector<int>>& computers, vector<bool>& isVisited) {
    for(int i = 0; i < computers.size(); i++) {
        if(!isVisited[i] && i != node && computers[node][i] == 1) {
            isVisited[i] = true;
            dfs(i, computers, isVisited);
        }
    }
    return;
}