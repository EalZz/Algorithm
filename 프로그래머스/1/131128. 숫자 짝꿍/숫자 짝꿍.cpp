#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    vector<int> v;
    unordered_map<char, int> freq;
    
    for (char ch : Y) freq[ch]++;
    
    //사용한 문자 감소
    for (char ch : X) {
        if (freq[ch] > 0) {
            v.push_back(ch - '0');
            freq[ch]--; 
        }
    }

    if (v.empty()) return "-1";
    sort(v.begin(), v.end(), [](int x, int y) { return x > y; });
    if (v.front() == 0) return "0";
    for (auto i : v) answer.push_back(i + '0');

    return answer;
}