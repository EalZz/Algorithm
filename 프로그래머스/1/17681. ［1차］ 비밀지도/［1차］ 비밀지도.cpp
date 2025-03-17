#include <string>
#include <vector>

using namespace std;
string tobinary(int n, int num);

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector <string> v1, v2, v;
    for(int i = 0; i < n; i++){
        v1.push_back(tobinary(n, arr1[i]));
        v2.push_back(tobinary(n, arr2[i]));
    }
    for(int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            s.push_back((v1[i][j] == '0' && v2[i][j] == '0') ? ' ' : '#');
        }
        v.push_back(s);
    }
    return v;
}

string tobinary(int n, int num) {
    string s (n, '0');
    for(int j = 0; j < n; j++){
        s[n - 1 - j] = num % 2 + '0';
        num /= 2;
    }
    return s;
}