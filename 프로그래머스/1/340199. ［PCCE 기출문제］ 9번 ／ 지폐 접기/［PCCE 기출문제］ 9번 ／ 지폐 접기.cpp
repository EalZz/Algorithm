#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    sort(wallet.begin(), wallet.end());
    
    while(1) {
        sort(bill.begin(), bill.end());
        if(wallet[0] >= bill[0] && wallet[1] >= bill[1]) return answer;
        if(bill[0] >= bill[1]) {
            bill[0] /= 2;
            answer++;
        }
        else {
            bill[1] /= 2;
            answer++;
        }
    }
}