#include <string>
#include <vector>

using namespace std;

void count(vector<int> numbers, int target, int sum, int idx);
int cnt = 0;

int solution(vector<int> numbers, int target) {
    count(numbers, target, 0, 0);
    return cnt;
}

void count(vector<int> numbers, int target, int sum, int idx) {
    if(idx >= numbers.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    count(numbers, target, sum + numbers[idx], idx + 1);
    count(numbers, target, sum - numbers[idx], idx + 1);
    
    return;
}