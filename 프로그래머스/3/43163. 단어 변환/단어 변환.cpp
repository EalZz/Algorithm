#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> bfs;
    vector<bool> isVisited(words.size(), false);
    bfs.push({begin, 0});
    
    while(!bfs.empty()) {
        string usingword = bfs.front().first;
        int currentLevel = bfs.front().second;
        bfs.pop();
        
        if(usingword == target) return currentLevel;

        for(int i = 0; i < words.size(); i++) {
            if(!isVisited[i]) {
                int cnt = 0;
                for(int j = 0; j < words[i].size(); j++) {
                    if(usingword[j] != words[i][j]) cnt++;
                    if(cnt > 1) break;
                }
                if(cnt == 1) {
                    isVisited[i] = true;
                    bfs.push({words[i], currentLevel + 1});
                }
            }
        }
    }
    
    return 0;
}
//int dfs(string begin, string target, vector<string> words