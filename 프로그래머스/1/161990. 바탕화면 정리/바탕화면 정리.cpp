#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4, -1);
    for(int i = 0; i < wallpaper.size(); i++){
        if(answer[0] == -1) {
            if(wallpaper[i].find('#') != string::npos) {
                answer[0] = i;
                answer[2] = i + 1;
            }
        } 
        else {
            if(wallpaper[i].find('#') != string::npos) answer[2] = i + 1;
        }
        
        if(answer[1] == -1 || answer[3] == -1) {
            if(wallpaper[i].find('#') != string::npos) {
                answer[1] = wallpaper[i].find('#');
                answer[3] = wallpaper[i].rfind('#') + 1;
            } 
        }
        else {
            if(answer[1] > wallpaper[i].find('#')) answer[1] = wallpaper[i].find('#');
            if(answer[3] < wallpaper[i].rfind('#') + 1) answer[3] = wallpaper[i].rfind('#') + 1;
        }
    }
    return answer;
}