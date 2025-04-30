#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    map<string, int> md, mw;
    int answer = 0, loop = 0;
    
    for(int i = 0; i < want.size(); i++) {
        mw[want[i]] = number[i];
        loop += number[i];
    }
    
    for(int i = 0; i + loop <= discount.size(); i++) {
        md.clear();
        
        for(int j = 0; j < loop; j++) md[discount[i + j]]++;
        
        bool chk = true;
        for(auto w : want) {
            if(md[w] != mw[w]) {
                chk = false;
                break;
            }
        }
        if(chk) answer++;
    }
    
    return answer;
}