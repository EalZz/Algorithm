#include<vector>
#include <queue>
#include <utility>
using namespace std;

int solution(vector<vector<int> > maps)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    int n = maps.size();
    int m = maps[0].size();
    //방문여부, 거리계산 (미방문 -1)
    vector<vector<int>> v(n, vector<int>(m, -1));
    v[0][0] = 1;
    
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    
    while(!q.empty()) {
        //현재 위치
        pair<int, int> current = q.front();
        q.pop();
        
        int y = current.first;
        int x = current.second;
        
        //목적지에 도착했는지 확인
        if (y == n-1 && x == m-1) return v[y][x];
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            //맵 내부, 갈수 있는 구역, 미방문 구역인지 확인
            if ((ny >= 0 && ny < n && nx >= 0 && nx < m) && 
                maps[ny][nx] == 1 && v[ny][nx] == -1) {
                q.push({ny, nx});
                v[ny][nx] = v[y][x] + 1;
            }
        }
    }
    return -1;
}