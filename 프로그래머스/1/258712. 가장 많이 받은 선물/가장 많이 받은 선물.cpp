#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    vector<vector<string>> gift(gifts.size()); 
    map<string, map<string, int>> givetake;
    map<string, int> gift_score;
    map<string, int> gifted;
    
    for(auto f1 : friends) {
        gift_score[f1] = 0;
        gifted[f1] = 0;
        for(auto f2 : friends) givetake[f1][f2] = 0;
    }
    for(int i = 0; i < gifts.size(); i++) {
        stringstream ss(gifts[i]);
        string word;
        while(ss >> word) gift[i].push_back(word);
    }
    
    for(auto g : gift){
        givetake[g[0]][g[1]]++;                         //준 횟수 계산
        gift_score[g[0]]++;                             //선물 지수 계산 (주면 +1 받으면 -1)
        gift_score[g[1]]--;
    }
    
    for(auto f1 : friends) {
        cout << f1 << " ";
        for(auto f2 : friends) {
            if(f1 == f2) continue;
            if(givetake[f1][f2] > givetake[f2][f1]) gifted[f1]++;
            if(givetake[f1][f2] == givetake[f2][f1]) {
                if(gift_score[f1] > gift_score[f2]) gifted[f1]++;
            }
        }
        if(answer < gifted[f1]) answer = gifted[f1];
        cout << gifted[f1] << endl;
    }
    
    

cout << "G\R";
for(auto& f : friends) {
    cout << "\t" << f;
}
cout << "\n";

for(auto& f1 : friends) {
    cout << f1;
    for(auto& f2 : friends) {
        cout << "\t" << givetake[f1][f2];
    }
    cout << "\n";
}
    
    
    return answer;
}