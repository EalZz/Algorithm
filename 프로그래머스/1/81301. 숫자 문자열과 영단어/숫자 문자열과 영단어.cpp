#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int i = 0;
    
    vector<pair<string, int>> nums = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    while (i < s.size()) {
        if (isdigit(s[i])) { 
            answer = answer * 10 + (s[i] - '0');
            i++;
        } else { // 문자열인 경우
            for (auto& [word, num] : nums) {
                if (s.substr(i, word.size()) == word) {
                    answer = answer * 10 + num;
                    i += word.size();
                    break;
                }
            }
        }
    }
    
    return answer;
}