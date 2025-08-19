#include <string>
#include <vector>

using namespace std;

void network(int pc, vector<vector<int>>& computers, vector<bool>& isVisited);

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> isVisited(n, false);
    
    for(int i = 0; i < computers.size(); i++) {
        if(!isVisited[i]) {
            network(i, computers, isVisited);
            answer++;
        }
    }
    
    return answer;
}

void network(int pc, vector<vector<int>>& computers, vector<bool>& isVisited) {
    isVisited[pc] = true;
    
    for(int i = 0; i < computers[pc].size(); i++) {
        if(!isVisited[i] && pc != i && computers[pc][i] == 1) {
            
            network(i, computers, isVisited);
        }
    }
    return;
}