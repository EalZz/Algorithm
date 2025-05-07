#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, vector<string>> m;
    
    for(auto s : clothes) m[s[1]].push_back(s[0]);
    for(auto n : m) answer *= n.second.size() + 1; //입지 않은 상태를 표현하기 위해 + 1
    
    return answer - 1; //전부 안입은 상태 - 1
}