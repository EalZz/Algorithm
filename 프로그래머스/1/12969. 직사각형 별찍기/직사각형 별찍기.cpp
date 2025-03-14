#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int a;
    int b;
    string s;
    cin >> a >> b;
    
    while(a--) s.push_back('*');
    while(b--) cout << s << endl;
    
    return 0;
}