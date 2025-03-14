#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> v;
    for(int i = 1; i <= n; i++) v.push_back(x * i);
    
    return v;
}