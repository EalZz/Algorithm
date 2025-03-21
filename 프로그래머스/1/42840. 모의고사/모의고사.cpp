#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer, 
    onev {1, 2, 3, 4, 5}, 
    twov {2, 1, 2, 3, 2, 4, 2, 5}, 
    thrv {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int cnta = 0, cntb = 0, cntc = 0;
    
    for(int i = 0; i < answers.size(); i++) {
        if(onev[i % 5] == answers[i]) cnta++;
        if(twov[i % 8] == answers[i]) cntb++;
        if(thrv[i % 10] == answers[i]) cntc++;
    }
    
    if(cnta == cntb) {
        if (cnta == cntc) return {1, 2, 3};
        if (cnta > cntc) return {1, 2};
        if (cnta < cntc) return {3};
    } 
    else if(cnta == cntc) {
        if (cnta > cntb) return {1, 3};
        if (cnta < cntb) return {2};
    }
    else if(cntb == cntc) {
        if (cnta > cntb) return {1};
        if (cnta < cntb) return {2, 3};
    }
    else if(cnta > cntb){
        if(cnta > cntc) return {1};
        else return {3};
    }
    else if(cntb > cntc) {
        if(cntb > cnta) return {2};
        else return {1};
    }
    else if(cnta < cntc){
        if(cntb < cntc) return {3};
        else return {2};
    }
    return answer;
}