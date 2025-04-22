#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int f_idx = 0, b_idx = people.size() - 1 , sum = 0;
    sort(people.begin(), people.end());
    
    while(f_idx <= b_idx) {
        if(people[f_idx] + people[b_idx] <= limit) {
            f_idx++;
            b_idx--;
            answer++;
        }
        else {
            b_idx--;
            answer++;
        }
    }
    
    
    return answer;
}