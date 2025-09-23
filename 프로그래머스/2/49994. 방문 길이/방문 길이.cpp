#include <string>
#include <vector>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool isVisited[15][15][4] = {false, };
    int cur_y = 5; int cur_x = 5;
    
    for(auto& dir : dirs) {
        int prev_y = cur_y, prev_x = cur_x;
        int idir = 0;
        switch(dir) {
            case 'U' :
                idir = 0;
                cur_y++;
                break;
            case 'D' :
                idir = 3;
                cur_y--;
                break;
            case 'R' :
                idir = 1;
                cur_x++;
                break;
            case 'L' : 
                idir = 2;
                cur_x--;
                break;
        }
        
        if(cur_y > 10 || cur_y < 0) {
            cur_y = prev_y;
            continue;
        }
        if(cur_x > 10 || cur_x < 0){
            cur_x = prev_x;
            continue;
        }
        
        if(!isVisited[cur_y][cur_x][idir] && !isVisited[prev_y][prev_x][3 - idir]) {
            isVisited[cur_y][cur_x][idir] = true;
            answer++;
        }
    }
    
    return answer;
}