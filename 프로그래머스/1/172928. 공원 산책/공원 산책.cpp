#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> location(2);
    vector<int> tmp(2);
    vector<vector<string>> route(routes.size());
    
    //좌표 벡터에 시작 좌표 넣기
    for(int i = 0; i < park.size(); i++) {
        for(int j = 0; j < park[i].size(); j++) {
            if(park[i][j] == 'S') {
                location[0] = i;
                location[1] = j;
            }
        }
    }
    
    //공백기준으로 루트 나누기 
    for(int i = 0; i < routes.size(); i++) {
        stringstream ss(routes[i]);
        string s1;
        while(ss >> s1) route[i].push_back(s1);
    }
    //이동
    for(auto vr : route) {
        //원래 위치 저장
        tmp[0] = location[0]; 
        tmp[1] = location[1];
        
        //1칸씩 이동
        for(int i = 0; i < stoi(vr[1]); i++){
            if(vr[0] == "E") location[1]++;
            else if(vr[0] == "W") location[1]--;
            else if(vr[0] == "S") location[0]++;
            else if(vr[0] == "N") location[0]--;
            
            //장애물을 만나거나 공원에서 넘어가면 롤백
            if(location[0] >= park.size() || location[1] >= park[location[0]].size()
                || location[0] < 0 || location[1] < 0
                || park[location[0]][location[1]] == 'X') {
                location[0] = tmp[0]; 
                location[1] = tmp[1];
                break;
            }
        }
    }
    
    return location;
}