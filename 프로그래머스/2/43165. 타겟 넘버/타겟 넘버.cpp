#include <string>
#include <vector>

using namespace std;
int cnt = 0;
void dfs(int idx, int sum, int target, vector<int> numbers);

int solution(vector<int> numbers, int target) {
    dfs(0, 0, target, numbers);
    return cnt;
}

void dfs(int idx, int sum, int target, vector<int> numbers) {
    if(idx == numbers.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    dfs(idx + 1, sum + numbers[idx], target, numbers);
    dfs(idx + 1, sum - numbers[idx], target, numbers);
    
    return;
}
