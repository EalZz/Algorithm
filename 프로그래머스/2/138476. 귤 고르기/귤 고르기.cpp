#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int sum = 0, answer = 0;
    map<int, int> cntm;
    vector<int> cnts;

    for(int t : tangerine) cntm[t]++;

    for(auto cm : cntm) cnts.push_back(cm.second);
    sort(cnts.begin(), cnts.end(), greater<int>());

    for(int c : cnts) {
        sum += c;
        answer++;
        if (sum >= k) break;
    }

    return answer;
}
