#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<int> vtoday;
    vector<vector<string>> vterms;
    int num = 0, cnt = 0;
    
    //날짜 벡터에 저장
    //stoi와 일수변환을 사용해서 하는게 좀 더 편하고 코드도 짧아졌을 듯
    for(auto c : today) {
        if(c == '.') {
            vtoday.push_back(num);
            num = 0; cnt = 0;
            continue;
        }
        num = num * 10 + (c - 48);
        cnt++;
    }
    if(cnt > 0) vtoday.push_back(num);
    cnt = 0;
    
    //약관 2차원 string에 저장
    vterms.resize(terms.size());
    for(int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        string word;
        // 공백으로 구분된 각 단어를 추출하여 vterms[i]에 저장
        while(ss >> word) {
            vterms[i].push_back(word);
        }
    }
    
    //파기해야 할 개인정보 계산
    for(int i = 0; i < privacies.size(); i++) {
        vector<int> stoday;
        //약관 별로 계산
        num = 0, cnt = 0;
        for(int j = 0; j < vterms.size(); j++) {
            //약관 종류에 맞게 계산
            if (privacies[i].find(vterms[j][0]) != string::npos) {
                
                //수집일자 저장
                for(auto c : privacies[i]) {
                    if(c == ' ') break;
                    if(c == '.') {
                        stoday.push_back(num);
                        num = 0; cnt = 0;
                        continue;
                    }
                    num = num * 10 + (c - 48);
                    cnt++;
                }
                if(cnt > 0) stoday.push_back(num);
                cnt = 0;
                
                //파기일자 계산
                stoday[1] += stoi(vterms[j][1]);
                if(stoday[1] > 12) {
                    stoday[0] += (stoday[1] - 1) / 12;
                    stoday[1] = (stoday[1] - 1) % 12 + 1;
                }
                
                //연, 달, 일 순으로 비교
                if(stoday[0] > vtoday[0]) continue;
                else if(stoday[0] == vtoday[0]) {
                    if(stoday[1] > vtoday[1]) continue;
                    else if(stoday[1] == vtoday[1]) {
                        if(stoday[2] > vtoday[2]) continue;
                    }
                }
                answer.push_back(i + 1);
            }
        }
    }
    
    
    return answer;
}