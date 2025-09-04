#include <string>
#include <vector>

using namespace std;\
void network(int i, vector<vector<int>>& computers, vector<bool>& isVisited);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isVisited(n, false);
    
    for(int i = 0; i < computers.size(); i++) {
        if(!isVisited[i]) {
            answer++;
            network(i, computers, isVisited);
        }
    }
    
    return answer;
}

void network(int i, vector<vector<int>>& computers, vector<bool>& isVisited) {
    for(int j = 0; j < computers[i].size(); j++) {
        if(!isVisited[j] && i != j && computers[i][j] == 1) {
            isVisited[j] = true;
            network(j, computers, isVisited);
        }
    }
}