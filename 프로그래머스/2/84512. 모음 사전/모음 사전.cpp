#include <string>
#include <vector>
#include <iostream>

using namespace std;
int answer = 0;
int cnt;

void dfs(string s, string target, vector<char>& v);

int solution(string word) {
    vector<char> v = {'A', 'E', 'I', 'O', 'U'};
    dfs("", word, v);
  
    return answer;
}

void dfs(string s, string target, vector<char>& v) {
    if(s == target) {
        answer = cnt;
        return;
    }
    cnt++;
    if(s.size() >= 5) return;
    for(int i = 0; i < v.size(); i++) dfs(s + v[i], target, v);
}