#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int x = 0, y = 0;
    
    for(int i  = 0; i < sizes.size(); i++){
        sort(sizes[i].begin(), sizes[i].end());
        if(x < sizes[i][0]) x = sizes[i][0];
        if(y < sizes[i][1]) y = sizes[i][1];
    }
    
    return x * y;
}