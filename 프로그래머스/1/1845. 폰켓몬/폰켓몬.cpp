#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int i = nums.size() / 2, count = 0, p_count = 0;
    
    sort(nums.begin(), nums.end());
    
    while(count < nums.size()){
        if(nums[count] != nums[count + 1]){
            p_count++;
            cout << count + 1 << "다른 포켓몬 발견" << endl;
        }
        if(p_count == i){
            cout << "최대치" << endl;
            break;
        }
        count++;
    }
    
    return p_count;
}