#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int scores[8] = {0};

    for (int i = 0; i < survey.size(); i++) {
        char first = survey[i][0];  
        char second = survey[i][1]; 
        int choice = choices[i];

        int score = abs(choice - 4); 
        if (choice < 4) { 
            if (first == 'R') scores[0] += score;
            else if (first == 'T') scores[1] += score;
            else if (first == 'C') scores[2] += score;
            else if (first == 'F') scores[3] += score;
            else if (first == 'J') scores[4] += score;
            else if (first == 'M') scores[5] += score;
            else if (first == 'A') scores[6] += score;
            else if (first == 'N') scores[7] += score;
        } 
        else if (choice > 4) { 
            if (second == 'R') scores[0] += score;
            else if (second == 'T') scores[1] += score;
            else if (second == 'C') scores[2] += score;
            else if (second == 'F') scores[3] += score;
            else if (second == 'J') scores[4] += score;
            else if (second == 'M') scores[5] += score;
            else if (second == 'A') scores[6] += score;
            else if (second == 'N') scores[7] += score;
        }
    }

    answer += (scores[0] >= scores[1]) ? 'R' : 'T';
    answer += (scores[2] >= scores[3]) ? 'C' : 'F';
    answer += (scores[4] >= scores[5]) ? 'J' : 'M';
    answer += (scores[6] >= scores[7]) ? 'A' : 'N';

    return answer;
}