#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    string mida = "";
    
    //1, 2단계
    for(auto word : new_id){
        if(word >= 65 && word <= 90) word += 32;
        if((word >= 97 && word <= 122) || word >= 48 && word <= 57 
           || word == '-' || word == '_' || word == '.') 
            mida.push_back(word);
    }
    
    //3단계
    for(int i = 0; i < mida.size(); i++) {
        if(mida[i] == '.') {
            if((mida[i + 1] == '.') && (i != mida.size() - 1)) continue;
        }
        answer.push_back(mida[i]);
    }
    
    //4, 5단계
    if(answer.front() == '.') answer.erase(answer.begin());
    if(answer.back() == '.') answer.pop_back();
    if(answer.empty()) answer.push_back('a');
    
    //6단계
    if(answer.size() >= 16){
        int len = answer.size();
        for(int i = len; i >= 16; i--) answer.pop_back();
    }
    if(answer.back() == '.') answer.pop_back();
    
    //7단계
    if(answer.size() <= 2){
        int len = answer.size();
        for(int i = len; i <= 2; i++) answer.push_back(answer.back());
    }
    
    return answer;
}