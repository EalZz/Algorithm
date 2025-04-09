#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int idx1 = 0, idx2 = 0;
    for (string word : goal) {
        //사용해야 하는 카드 중 나와야하는 카드가 있는지 체크
        //있으면 인덱스 증가 후 다음 단어 탐색, 둘 다 없으면 No반환
        if (idx1 < cards1.size() && cards1[idx1] == word) idx1++;
        else if (idx2 < cards2.size() && cards2[idx2] == word) idx2++; 
        else return "No"; 
    }
    return "Yes";
}