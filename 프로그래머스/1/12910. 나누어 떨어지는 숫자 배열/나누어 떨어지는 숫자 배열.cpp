#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> s;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] % divisor == 0)
            s.push_back(arr[i]);
    }
    if(s.empty())
        s.push_back(-1);
    sort(s.begin(), s.end());
    
    return s;
}