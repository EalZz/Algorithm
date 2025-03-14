#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    vector<int> v;
    int cnt = 0;
    
    for(int i = 0; i < nums.size() - 2; i++){
        for(int j = i + 1; j < nums.size() - 1; j++){
            for(int k = j + 1; k < nums.size(); k++){
                v.push_back(nums[i] + nums[j] + nums[k]); 
            }
        }
    }
    
    int max = *max_element(v.begin(), v.end());
    std::vector<bool> isPrime (max + 1, true);
    
    isPrime[0] = isPrime[1] = false;
    
    for(int i = 2; i <= sqrt(max); i++){
        if(!isPrime[i]) continue;
        for(int j = i * i;  j <= max; j += i){
            isPrime[j] = false;
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        if(isPrime[v[i]]) cnt++;
    }
    
    return cnt;
}