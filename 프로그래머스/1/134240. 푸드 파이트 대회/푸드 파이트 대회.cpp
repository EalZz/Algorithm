#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";
    
    for(int i = 1; i < food.size(); i++) {
        int cnt = food[i] / 2;
        while(cnt--) answer.push_back(i + '0');
    }
    answer.push_back('0');
    for(int i = answer.size() - 2; i >= 0; i--) answer.push_back(answer[i]);
    
    return answer;
}