#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for(int i = 1; i <= sqrt(yellow); i++) {
        if((yellow % i == 0) && (i + yellow / i + 2 == brown / 2)) return {yellow / i + 2, i + 2};
    } 
}