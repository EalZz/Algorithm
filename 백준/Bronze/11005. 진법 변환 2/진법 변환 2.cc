#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int b = 0, n = 0, result_i;
    string result = "";
    cin >> n >> b;

    while (n > 0) {
        int result_i = n % b;
        if (result_i >= 10) {
            result += (result_i - 10) + 'A';  
        }
        else {
            result += result_i + '0'; 
        }
        n = n / b;
    }

    int len_r = result.length();

    for (int i = 0; i < len_r; i++) {
        cout << result[len_r - 1 - i];
    }

    return 0;
}