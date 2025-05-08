#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day = 1;
    int tmp = ((100 - progresses[0]) + speeds[0] - 1) / speeds[0]; 

    for(int i = 1; i < progresses.size(); i++) {
        int cur = ((100 - progresses[i]) + speeds[i] - 1) / speeds[i];  
        if(tmp < cur) {
            answer.push_back(day);
            tmp = cur;
            day = 1;
        }
        else day++;
    }
    answer.push_back(day);

    return answer;
}
