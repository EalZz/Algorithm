#include <string>
#include <vector>

using namespace std;
int cnt = 0;
void dfs(int sum, int idx, vector<int> numbers, int target);

int solution(vector<int> numbers, int target) {
    dfs(0, 0, numbers, target);
    return cnt;
}

void dfs(int sum, int idx, vector<int> numbers, int target) {
    if(idx == numbers.size()) {
        if(sum == target) cnt++;
        return;
    }
    
    dfs(sum + numbers[idx], idx + 1, numbers, target);
    dfs(sum - numbers[idx], idx + 1, numbers, target);
    
    return;
}