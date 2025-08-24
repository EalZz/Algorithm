#include <string>
#include <vector>

using namespace std;

void network(int pc, vector<vector<int>>& computers, vector<bool>& isVisited);

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

void network(int pc, vector<vector<int>>& computers, vector<bool>& isVisited) {
    for(int i = 0; i < computers[pc].size(); i++) {
        if(i != pc && !isVisited[i] && computers[pc][i] == 1) {
            isVisited[i] = true;
            network(i, computers, isVisited);
        }
    }
    return;
}