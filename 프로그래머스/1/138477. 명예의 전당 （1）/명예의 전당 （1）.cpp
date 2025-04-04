#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    vector<int> temp;
    
    answer.push_back(score[0]);
    temp.push_back(score[0]);
    if(score.size() > k) {
        for(int i = 1; i < k; i++) {
            answer.push_back(score[i] < answer[i - 1] ? score[i] : answer[i - 1]);
            temp.push_back(score[i]);
        }
        for(int i = k; i < score.size(); i++) {
            temp.push_back(score[i]);
            sort(temp.begin(), temp.end(), [](int x, int y) {return x > y;});
            answer.push_back(temp[k - 1]);
        }
    }
    else {
        for(int i = 1; i < score.size(); i++)
            answer.push_back(score[i] < answer[i - 1] ? score[i] : answer[i - 1]);
    }
    
    return answer;
}