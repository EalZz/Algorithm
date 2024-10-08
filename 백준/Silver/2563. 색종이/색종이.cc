#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
   
    int row = 100, col = 100;
    //cin >> row >> col;

    int** arr = new int* [row];
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            arr[i][j] = 0;
        }
    }

    int count = 0, result = 0;
    cin >> count;

    for (int i = 0; i < count; i++) {
        int x = 0, y = 0;
        cin >> x >> y;
        for (int i = x; i <  x + 10; i++) {
            for (int j = y; j < y + 10; j++) {
                arr[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] == 1)
                result++;
        }
    }

    cout << result;

    return 0;
}