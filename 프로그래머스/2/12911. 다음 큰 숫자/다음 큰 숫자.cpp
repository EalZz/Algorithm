#include <string>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt_one = 0, cnt_zero = 0, b_chk = 0;
    string sn = "", tmp_n = "";
    bool is_zero = false;
    
    while(n > 0) {
        sn = to_string(n % 2) + sn;
        n /= 2;
    }
    tmp_n = sn;
    
    for(int i = sn.size() - 1; i >= 0; i--) {
        if(sn[i] == '0') cnt_zero++;
        else if(sn[i] == '1') cnt_one++;
        tmp_n.pop_back();
        if(i != sn.size() - 1 && sn[i] == '0' && sn[i + 1] =='1') {
            is_zero = true;
            break;
        }
    }
    
    if(!is_zero) {
        tmp_n = "10";
        while(cnt_zero--) tmp_n.push_back('0');
        while(--cnt_one) tmp_n.push_back('1');
    }
    else{
        tmp_n.push_back('1'); cnt_one--;
        while(cnt_zero--) tmp_n.push_back('0');
        while(cnt_one--) tmp_n.push_back('1');
    }
    
    for(int i = tmp_n.size() - 1; i >= 0; --i) {
        if(tmp_n[i] == '1') answer+= pow(2, b_chk);
        b_chk++;
    }
    
    return answer;
}