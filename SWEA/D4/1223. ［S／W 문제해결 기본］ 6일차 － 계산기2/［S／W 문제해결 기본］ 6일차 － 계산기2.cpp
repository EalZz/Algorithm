#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char** argv) {
    for(int i = 1; i <= 10; i++){
        int cnt = 0;
        string s1 = "", s2 = "";

        cin >> cnt;
        //후위표기법으로 전환해서 s1에 저장
        while (cnt--) {
            char c;
            cin >> c;

            if (isdigit(c)) s1.push_back(c);
            else if (s2.empty()) s2.push_back(c);
            else if (c == '*') s2.push_back(c);
            else if (c == '+') {
                while (!s2.empty()) {
                    char tmp = s2.back();
                    s1.push_back(tmp);
                    s2.pop_back();
                }
                s2.push_back(c);
            }
        }
        while (!s2.empty()) {
            char tmp = s2.back();
            s1.push_back(tmp);
            s2.pop_back();
        }

        //계산
        vector<string> s3;
        for (auto s : s1) {
            string c(1, s);
            if (isdigit(s)) s3.push_back(c);
            else {
                int tmp1 = stoi(s3.back()); s3.pop_back();
                int tmp2 = stoi(s3.back()); s3.pop_back();
                switch (s) {
                case '+':
                    s3.push_back(to_string(tmp1 + tmp2));
                    break;
                case '*':
                    s3.push_back(to_string(tmp1 * tmp2));
                    break;
                }
            }
        }
        cout << "#" << i << " " << s3.back() << endl;
    }
    return 0;
}