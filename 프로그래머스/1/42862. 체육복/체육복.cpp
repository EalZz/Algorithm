#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    
     for(int i = lost.size() - 1; i >= 0; i--){
        if(find(reserve.begin(), reserve.end(), lost[i]) != reserve.end()) {
            reserve.erase(remove(reserve.begin(), reserve.end(), lost[i]), reserve.end());
            lost.erase(lost.begin() + i);
            answer++;
        }
    }
    
    for(int i = 0; i < lost.size(); i++){
        if(find(reserve.begin(), reserve.end(), lost[i] - 1) != reserve.end()) {
            reserve.erase(remove(reserve.begin(), reserve.end(), lost[i] - 1), reserve.end());
            answer++;
        }
        else if(find(reserve.begin(), reserve.end(), lost[i] + 1) != reserve.end()) {
            reserve.erase(remove(reserve.begin(), reserve.end(), lost[i] + 1), reserve.end());
            answer++;
        }
    }
    
    return answer;
}