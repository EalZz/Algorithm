#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer(4, -1);
    for(int i = 0; i < wallpaper.size(); i++){
        //비어있으면 일단 넣음 (#이 1개인 경우도 같이 해결), 최솟값 같이 해결
        if(answer[0] == -1) {
            if(wallpaper[i].find('#') != string::npos) {
                answer[0] = i;
                answer[2] = i + 1;
            }
        } 
        //최댓값만 찾으면 됨, 찾은 인덱스에서 + 1
        else {
            if(wallpaper[i].find('#') != string::npos) answer[2] = i + 1;
        }
        //비어있으면 일단 넣음 (#이 1개인 경우도 같이 해결), 최댓값은 뒤에서부터 찾아야함
        if(answer[1] == -1) {
            if(wallpaper[i].find('#') != string::npos) {
                answer[1] = wallpaper[i].find('#');
                answer[3] = wallpaper[i].rfind('#') + 1;
            } 
        }
        //최소, 최댓값 둘 다 확인
        else {
            if(answer[1] > wallpaper[i].find('#')) answer[1] = wallpaper[i].find('#');
            if(answer[3] < wallpaper[i].rfind('#') + 1) answer[3] = wallpaper[i].rfind('#') + 1;
        }
    }
    return answer;
}