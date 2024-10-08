#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    /*
    int row = 9, col = 9;
    int max = -1;
    int *index = new int[2];
    cin >> row >> col;

    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }
    */
    string str[5];
    for (int i = 0; i < 5; i++) {
        int len = str[i].length();
        cin >> str[i];
        if (len < 16) {
            str[i] += string(15 - len, ' ');
        }
    }
    
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 5; j++) {
            if (str[j][i] == ' ')
                continue;
            cout << str[j][i];
        }
    }

    return 0;
}