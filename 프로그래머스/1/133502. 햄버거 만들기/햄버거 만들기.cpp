#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    
    for(auto i : ingredient) {
        v.push_back(i);
        //v크기가 4이상이면 뒷 원소 4개를 확인
        if(v.size() >= 4) {
            int n = v.size();
            //뒷 원소 4개가 1231이면 pop 후 answer++
            if(v[n-4] == 1 && v[n-3] == 2 && v[n-2] == 3 && v[n-1] == 1) {
                v.pop_back(); 
                v.pop_back(); 
                v.pop_back(); 
                v.pop_back(); 
                answer++;
            }
        }
    }
    
    return answer;
}