#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    int idx = 0;
    int i = 0, j = 0;
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    if(participant.size() == 1) return participant[0];
    
    while(1) {
        if(participant[i] != completion[i]) {
            idx = i;
            break;
        }
        i++;
        j++;
    }
    
    return participant[i];
}