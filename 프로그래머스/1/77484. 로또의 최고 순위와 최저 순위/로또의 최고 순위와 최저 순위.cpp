#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int score(int i);

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int cnt = 0, cntz = 0, max = 0, min = 0;
    for(auto num : lottos) {
        if(num == 0) {
            cntz++;
            continue;
        }
        if(find(win_nums.begin(), win_nums.end(), num) != win_nums.end()) cnt++;
    }
    
    max = cnt + cntz;
    min = cnt;
    
    answer.push_back(score(max));
    answer.push_back(score(min));
    
    return answer;
}

int score(int i) {
    switch(i){
        case 0:
        case 1:
            return 6;
        case 2:
            return 5;
        case 3:
            return 4;
        case 4:
            return 3;
        case 5:
            return 2;
        case 6:
            return 1;
    }
}