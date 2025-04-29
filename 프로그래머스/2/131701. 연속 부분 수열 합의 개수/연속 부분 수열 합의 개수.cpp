#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    vector<int> v = elements;
    v.insert(v.end(), elements.begin(), elements.end());
    set<int> sums;
    
    for(int start = 0; start < elements.size(); start++) {
        for(int len = 1; len <= elements.size(); len++) { 
            int sum = 0;
            for(int i = len; i < len + start; i++) sum += v[i];
            sums.insert(sum);
        }
    }
    
    return sums.size();
}