#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int bonusCalc(int i, char bonus);

int solution(string dartResult) {
    vector <int> vnum ,vnumB;
    string bonuses;
    vector <string> options;
    int result = 0;
    
    for(int i = 0; i < dartResult.size(); i++){
        //원 점수 골라내기
        if(dartResult[i] >= '0' && dartResult[i] <= '9'){
            if(i > 0 && dartResult[i - 1] >= '0' && dartResult[i - 1] <= '9') {
                int dig = vnum.back() * 10 + dartResult[i] - '0';
                vnum.pop_back();
                vnum.push_back(dig);
            }
            else vnum.push_back(dartResult[i] - '0');
            
            options.push_back("");
        }
        
        //보너스
        else if(dartResult[i] >= 'A' && dartResult[i] <= 'Z') 
            bonuses.push_back(dartResult[i]);
        
        
        //옵션
        else if (dartResult[i] == '*' || dartResult[i] == '#') 
            options[vnum.size() - 1] = string(1, dartResult[i]);
        
    }
    
    for(int i = 0; i < vnum.size(); i++) {
        vnumB.push_back(bonusCalc(vnum[i], bonuses[i]));
        if(options[i] == "*"){
            if(i != 0){
                vnumB[i - 1] *= 2;
                vnumB[i] *= 2;
            }
            else vnumB[i] *= 2;
        }
        else if(options[i] == "#") vnumB[i] *= -1;
    }
    
    for(int i = 0; i < vnum.size(); i++) {
        result += vnumB[i];
    }
    
    return result;
}

int bonusCalc(int score, char bonus) {
    switch (bonus) {
        case 'S': return score;
        case 'D': return pow(score, 2);
        case 'T': return pow(score, 3);
    }
    return 0;
}