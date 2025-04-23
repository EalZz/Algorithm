#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer (2, 0);
    vector<string> usingword;
    usingword.push_back(words[0]);
    
    for(int i = 1; i < words.size(); i++) {
        if(find(usingword.begin(), usingword.end(), words[i]) != usingword.end() || 
           words[i - 1].back() != words[i].front()) {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }
        usingword.push_back(words[i]);
    }

    return answer;
}