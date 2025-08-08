#include <string>
#include <vector>

using namespace std;
void network(int node, vector<vector<int>>& computers, vector<bool>& isVisited);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isVisited(n, false);
    
    for(int i = 0; i < n; i++) {
        if(!isVisited[i]) {
            answer++;
            network(i, computers, isVisited);
        }
    }
    
    return answer;
}

void network(int node, vector<vector<int>>& computers, vector<bool>& isVisited) {
    if(!isVisited[node]) isVisited[node] = true;
    
    for(int i = 0; i < computers[node].size(); i++) {
        if(computers[node][i] == 1 && i != node && !isVisited[i])
            network(i, computers, isVisited);
    }
    
    return;
}