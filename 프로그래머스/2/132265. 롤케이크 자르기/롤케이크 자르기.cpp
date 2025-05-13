#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int, int> a, b;

    //전체 토핑 저장
    for(int i = 0; i < topping.size(); i++)b[topping[i]]++;

    //왼쪽부터 탐색
    for(int i = 0; i < topping.size(); i++)
    {
        //있으면 b는 뺴고 a는 더 함
        b[topping[i]]--;
        a[topping[i]]++;
        
        //0이되면 토핑 삭제
        if(b[topping[i]] == 0)b.erase(topping[i]);
        
        //토핑의 갯수(map의 사이즈)가 같으면 answer++
        if(a.size() == b.size()) answer++;
    }

    return answer;
}