#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int cnt = 0, end = 0;
    
    for (auto s : section) {
        //페인트질 범위 밖(안칠해진 곳)만 체크
        if (s > end) {
            //페인트칠 한 끝 인덱스
            end = s + m - 1; 
            cnt++;
        }
    }
    
    return cnt;
}
