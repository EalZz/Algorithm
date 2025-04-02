#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> ong {"aya", "ye", "woo", "ma"};
    for(auto bab : babbling){
        bool possible = true;

        for(int i = 0; i < ong.size(); i++){
            auto it = bab.find(ong[i]);
            while ((it = bab.find(ong[i])) != string::npos) {
                bab.erase(it, ong[i].length());
                bab.insert(it, 1, '0' + i); 
                it++; 
            }
        }

        cout << bab << endl;
        
        if (!bab.empty() && (bab[0] < '0' || bab[0] > '9')) possible = false;

        for (size_t i = 1; i < bab.size(); i++) {
            if (bab[i] < '0' || bab[i] > '9' || bab[i] == bab[i - 1]) {
                possible = false;
                break;
            }
        }
        
        if(possible) answer++;
    }
    return answer;
}