#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string add(string a, string b);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m; 
    cin >> n >> m;
    
    vector<vector<string>> dp(101, vector<string>(101, "0"));
    
    // 초기값 설정
    for (int i = 0; i <= 100; i++) {
        dp[i][0] = "1";  // nC0 = 1
        dp[i][i] = "1";  // nCn = 1
    }
    
    // 파스칼의 삼각형: C(n,m) = C(n-1,m-1) + C(n-1,m)
    for (int i = 2; i <= 100; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] = add(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    
    cout << dp[n][m];
    
    return 0;
}

string add(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1;
    int j = b.length() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            sum += b[j] - '0';
            j--;
        }
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    
    reverse(result.begin(), result.end());
    return result;
}