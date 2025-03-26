#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer;
    vector<int> locationL = {-1, 0}, locationR = {1, 0} ;
    int locationC = 0;
    
    for(int num : numbers) {
        bool isLeft = false, isRight = false;
        switch (num) {
            case 1: locationL[1] = 3; isLeft = true; break;
            case 4: locationL[1] = 2; isLeft = true; break;
            case 7: locationL[1] = 1; isLeft = true; break;
                
            case 3: locationR[1] = 3; isRight = true; break;
            case 6: locationR[1] = 2; isRight = true; break;
            case 9: locationR[1] = 1; isRight = true; break;
               
            case 2: locationC = 3; break;
            case 5: locationC = 2; break;
            case 8: locationC = 1; break;
            case 0: locationC = 0; break;
        }
        if(isLeft) {
            locationL[0] = -1;
            answer.push_back('L');   
        }
        else if(isRight){
            locationR[0] = 1;
            answer.push_back('R');
        }
        else {
            int distanceL = abs(locationL[0]) + abs(locationL[1] - locationC);
            int distanceR = abs(locationR[0]) + abs(locationR[1] - locationC);
            if(distanceL < distanceR) {
                locationL = {0, locationC};
                answer.push_back('L');   
            }
            else if (distanceL > distanceR) {
                locationR = {0, locationC};
                answer.push_back('R');   
            }
            else {
                if(hand[0] == 'l') {
                    locationL = {0, locationC};
                    answer.push_back('L');
                }
                else {
                    locationR = {0, locationC};
                    answer.push_back('R');
                }
            }
        }
    }
    return answer;
}