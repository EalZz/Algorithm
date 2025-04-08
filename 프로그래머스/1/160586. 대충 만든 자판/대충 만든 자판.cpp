#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    for(int i = 0; i < targets.size(); i++) {
        for(auto t : targets[i]) {
            int cnt = 0;
            for(auto key : keymap){
                if(key.find(t) == string::npos) continue;
                if(cnt == 0) cnt = key.find(t) + 1;
                else if (cnt > key.find(t)) cnt = key.find(t) + 1;
            }
            if(cnt == 0) {
                answer[i] = -1;
                break;
            }
            else answer[i] += cnt;
        }
    }
    return answer;
}