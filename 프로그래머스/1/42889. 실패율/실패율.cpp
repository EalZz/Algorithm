#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>> v_idx;
    double sumA = 0, sumF = 0;
    
    for(int i = 0; i < N; i++){
        sumA = 0; 
        sumF = 0;
        for(int j = 0; j < stages.size(); j++) {
            if(i + 1 <= stages[j]) sumA++;
            if(i + 1 == stages[j]) sumF++;
        }
        if (!sumA) v_idx.push_back({0, i + 1});
        else v_idx.push_back({sumF / sumA, i + 1});
    }
    
    sort(v_idx.begin(), v_idx.end(), [](pair<double, int> a, pair<double, int> b) {
        if (a.first == b.first) return a.second < b.second;  // 실패율이 같으면 스테이지 번호 오름차순
        return a.first > b.first;  // 실패율 기준 내림차순
    });
    
    for(auto &[score, stage] : v_idx) answer.push_back(stage);
    
    return answer;
}
