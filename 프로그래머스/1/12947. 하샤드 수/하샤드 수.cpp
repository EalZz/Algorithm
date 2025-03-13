#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int sum = 0;
    string s = to_string(x);
    
    for(int i = 0; i < s.size(); i++) sum += s[i] - 48;
    
    return (x % sum == 0) ? true : false;
}