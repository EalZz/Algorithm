#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    for (int i = 1; i <= T; i++) {
        vector<string> vs(5);

        for (int j = 0; j < 5; j++) {
            getline(cin, vs[j]);
            if (vs[j].length() < 15) {
                vs[j] += string(15 - vs[j].length(), ' ');
            }
        }

        cout << "#" << i << " ";
        for (int col = 0; col < 15; col++) {
            for (int row = 0; row < 5; row++) {
                if (vs[row][col] != ' ') cout << vs[row][col];
            }
        }
        cout << endl;
    }
    return 0;
}
