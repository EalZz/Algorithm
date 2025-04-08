#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    
    for(int i = 0; i < targets.size(); i++) {
        for(auto t : targets[i]) {
            int cnt = 0;
            for(auto key : keymap){
                //찾으면 일단 cnt 할당
                if(key.find(t) == string::npos) continue;
                //이후 더 작은 것이 있으면 cnt 할당
                if(cnt == 0) cnt = key.find(t) + 1;
                else if (cnt > key.find(t)) cnt = key.find(t) + 1;
            }
            //keymap에 없으면 -1 반환 후 다음 targets으로
            if(cnt == 0) {
                answer[i] = -1;
                break;
            }
            //있으면 최소치만 저장 후 다음 글자 탐색
            else answer[i] += cnt;
        }
    }
    return answer;
}