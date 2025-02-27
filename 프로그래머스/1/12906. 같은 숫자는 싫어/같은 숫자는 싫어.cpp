#include <vector>
#include <iostream>
#include <iostream>
#include <stack>

using namespace std;

vector <int> solution(vector<int> arr) 
{
    vector<int> result;
    result.push_back(arr[0]);
    
    for (int i = 1; i < arr.size(); i++) {
        if (!result.empty() && result.back() == arr[i]) {
            result.pop_back(); 
            result.push_back(arr[i]);
        } else {
            result.push_back(arr[i]); 
        }
    }
    return result;
}