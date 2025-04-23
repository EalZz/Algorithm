#include <string>
#include <vector>
#include <algorithm>

using namespace std;
 
int Gcd(int a , int b);
 
int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i = 1; i < arr.size(); i++) {
        int gcd = Gcd(answer, arr[i]);
        int lcm = answer * arr[i] / gcd;
        answer = lcm;
    }
    return answer;
}

int Gcd(int a , int b) {
    int A = max(a, b);
    int B = min(a, b);
    
    while(A % B != 0) {
        int R = A % B;
        A = B;
        B = R;
    }
    return B;
}