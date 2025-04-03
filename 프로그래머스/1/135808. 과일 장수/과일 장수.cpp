#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    sort(score.begin(), score.end());
    
    while(score.size() / m){
        for(int i = 0; i < m - 1; i++) score.pop_back();
        answer += score.back() * m;
        score.pop_back();
    }
    
    return answer;
}