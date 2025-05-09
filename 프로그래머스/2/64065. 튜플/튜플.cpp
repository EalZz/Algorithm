#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> dv;
    int idx = 0, tmp = 0;
    
    for(int i = 1; i < s.size() - 1; i++) {
        if (s[i] == '{') dv.push_back(vector<int>()); 
        else if(isdigit(s[i])) tmp = tmp * 10 + s[i] - '0';
        else if (s[i] == ',' && isdigit(s[i - 1])) {
            dv[idx].push_back(tmp);
            tmp = 0;
        }
        else if(s[i] == '}') {
            dv[idx].push_back(tmp);
            tmp = 0;
            idx++;
        }
    }
    sort(dv.begin(), dv.end(), [](vector<int> a, vector<int> b) {
        return a.size() < b.size();
    });
    
    for (auto& v : dv) {
        for (int num : v) {
            if (find(answer.begin(), answer.end(), num) == answer.end()) answer.push_back(num);
        }
    }
    
    return answer;
}