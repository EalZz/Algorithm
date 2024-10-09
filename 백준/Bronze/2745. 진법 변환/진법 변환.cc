#include <iostream>
#include <string>
using namespace std;

int main() {
    int b = 0, ni = 0, result = 0;
    string n;
    cin >> n >> b;
    int len = n.length();

    for (int i = 0; i < len; i++) {
        if (isalpha(n[i])) {  
            ni = n[i] - 'A' + 10; 
        } else { 
            ni = n[i] - '0';
        }
        
        result = result * b + ni;  
    }

    cout << result << endl;

    return 0;
}