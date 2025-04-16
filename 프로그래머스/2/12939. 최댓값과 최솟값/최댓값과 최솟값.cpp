#include <string>
#include <vector>
#include <sstream>
#include <limits.h>

using namespace std;

string solution(string s) {
    vector<int> v;
    stringstream ss(s);
    string temp;
    int maxi = INT_MIN, mini = INT_MAX;
    
    while(ss >> temp) v.push_back(stoi(temp));
    
    for(auto i : v) {
        maxi = max(maxi, i);
        mini = min(mini, i);
    }
    
    return to_string(mini) + " " + to_string(maxi);;
}