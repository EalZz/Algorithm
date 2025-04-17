#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);

    while (s != "1") {
        int cnt = count(s.begin(), s.end(), '0'); 
        answer[1] += cnt;

        int len = s.size() - cnt;
        s = "";

        while (len > 0) {
            s = char(len % 2 + '0') + s;
            len /= 2;
        }

        answer[0]++;
    }

    return answer;
}
