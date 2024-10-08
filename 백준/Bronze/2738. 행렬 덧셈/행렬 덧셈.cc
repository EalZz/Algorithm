#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int row = 0, col = 0;
    cin >> row >> col;

    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }

    int n = 2;
    while (n--) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int sum = 0;
                cin >> sum;
                arr[i][j] += sum;
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}