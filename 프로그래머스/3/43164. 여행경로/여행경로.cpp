#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dfs(string airport, vector<vector<string>>& tickets, vector<string>& answer, vector<bool>& isVisited);

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> isVisited(tickets.size(), false);
    answer.push_back("ICN");
    
    sort(tickets.begin(), tickets.end(), [](vector<string>& a, vector<string>& b) {
        if(a[0] != b[0]) return a[0] < b[0];
        return a[1] < b[1];
    });
    
    dfs("ICN", tickets, answer, isVisited);
    
    return answer;
}

bool dfs(string airport, vector<vector<string>>& tickets, vector<string>& answer, vector<bool>& isVisited) {
    if(answer.size() == tickets.size() + 1) return true;
    
    for(int i = 0; i < tickets.size(); i++) {
        if(!isVisited[i] && airport == tickets[i][0]) {
            answer.push_back(tickets[i][1]);
            isVisited[i] = true;
            
            if(dfs(tickets[i][1], tickets, answer, isVisited)) return true;
            
            answer.pop_back();
            isVisited[i] = false;
        }
    }
    return false;
}