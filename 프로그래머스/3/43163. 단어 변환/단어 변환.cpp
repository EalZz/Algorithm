#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int>> bfs;
    vector<bool> isVisited(words.size(), false);
    bfs.push({begin, 0});

    while(!bfs.empty()){
        string usingword = bfs.front().first;
        int currentLevel = bfs.front().second;
        bfs.pop();
        
        if(usingword == target) return currentLevel;

        for(int j = 0; j < words.size(); j++) {
            int cnt = 0;
            if(!isVisited[j]) {
                for(int i = 0; i < words[j].size(); i++) {
                    if(words[j][i] != usingword[i]) cnt++;
                    if(cnt > 1) break;
                }
                if(cnt == 1) {
                    bfs.push({words[j], currentLevel + 1});
                    isVisited[j] = true;
                }
            }
        }
    }
    return 0;
}
//int dfs(string begin, string target, vector<string> words