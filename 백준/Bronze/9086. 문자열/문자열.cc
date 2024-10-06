#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string str;
    cin >> n;
    
    while(n--){
        cin >> str;
        cout << str[0]
            << str[str.size() - 1] << endl;
    }
    
    return 0;
}