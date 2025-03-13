#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    int len = arr.size();
    double sum = 0;
    
    while(len--){
        sum += arr[len];
    }
    
    return sum / arr.size();
}