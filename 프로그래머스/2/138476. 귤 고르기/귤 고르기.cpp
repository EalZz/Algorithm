#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0, sum = 0, cnt = 0;
    vector<int> idxs;
    
    sort(tangerine.begin(), tangerine.end());
    
    for(int i = 1; i < tangerine.size(); i++) {
        cnt++;
        if(tangerine[i - 1] != tangerine[i]) {
            idxs.push_back(cnt);
            cout << cnt << endl;
            cnt = 0;
        }
    }
    cnt++;
    idxs.push_back(cnt);
    cout << cnt << endl;
    
    sort(idxs.begin(), idxs.end(), greater<int>());
    for(auto i : idxs) {
        sum += i;
        answer++;
        if(sum >= k) break;
    }
    return answer;
}