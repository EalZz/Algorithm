#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i = 0; i < schedules.size(); i++) {
        int target = 0;
        //스케쥴이 50분 이상인경우(10분 추가할 시 시간이 바뀌는 경우)
        if(schedules[i] % 100 >= 50) target = schedules[i] + 50;
        else target = schedules[i] + 10;
        
        vector<bool> is_suc(7, false);
        //주말은 항상 true로
        //시작일이 일요일일 때
        if(startday == 7) {
            is_suc[0] = true;
            is_suc[6] = true;
        }
        else {
            is_suc[6 - startday] = true;
            is_suc[6 - startday + 1] = true;
        }
        
        
        //cout << "주말확인 "; 
        //for(auto a : is_suc) cout << a << " ";
        //cout << endl;
        
        //시작일 부터 체크
        for(int j = 0; j < timelogs[i].size(); j++) {
            //주말은 넘김
            if(is_suc[j]) continue;
            if(timelogs[i][j] <= target) is_suc[j] = true;
        }
        //cout << "직원"<< i + 1 << " "; 
        //for(auto a : is_suc) cout << a << " ";
        //cout << endl;
        
        if(find(is_suc.begin(), is_suc.end(), false) != is_suc.end()) continue;
        answer++;
        //cout << "성공" << endl;
    }
    
    return answer;
}