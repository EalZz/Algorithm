#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, sum = 0;
    cin >> n;
    
    char ch[101];
    cin >> ch;
    
    for(int i = 0; i < n; i++){
        sum += ch[i] - 48;
    }
    
    cout << sum <<endl;
    
    return 0;
}