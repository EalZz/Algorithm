#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t = 0;
    double evg, max = 0, sum = 0;
    cin >> t;

    int* arr_1 = new int[t];
    //int* arr_2 = new int[max];

    for (int i = 0; i < t; i++) {
        cin >> arr_1[i];
        sum += arr_1[i];
        if (max < arr_1[i])
            max = arr_1[i];
    }
    
    evg = (sum * 100 / max) / t;

    cout << evg << endl;

    return 0;
}