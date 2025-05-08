#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dfs(int k, vector<vector<int>> dungeons, vector<bool> visited, int clear);

int solution(int k, vector<vector<int>> dungeons) {
    vector<bool> visited(dungeons.size(), false);
    return dfs(k, dungeons, visited, 0);
}

int dfs(int k, vector<vector<int>> dungeons, vector<bool> visited, int clear) {
    int result = clear; //result를 클리어 수로 갱신
    for(int i = 0; i < dungeons.size(); i++) {
        if(visited[i] || dungeons[i][0] > k) continue; //필요피로도 미달, 클리어한 곳 패스 
        visited[i] = true; //클리어 처리
        
        result = max(result, dfs(k - dungeons[i][1], dungeons, visited, clear + 1)); //다음 탐험(피로도 뺌,클리어++), result중 최댓값으로 갱신
        
        visited[i] = false; //다른 탐색을 위해서 false
    }
    return result;
}