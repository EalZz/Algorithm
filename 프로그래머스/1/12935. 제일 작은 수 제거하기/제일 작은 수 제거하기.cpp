#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector <int> v = arr;
    sort(v.begin(), v.end());
    int i = v.front();
    arr.erase(remove(arr.begin(), arr.end(), i), arr.end());
    if(arr.empty()) arr.push_back(-1);
    return arr;
}