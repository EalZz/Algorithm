#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, max = 0;
    //cin >> t >> max;
    t = 30;
    max = 28;

    int* arr_1 = new int[t];
    int* arr_2 = new int[max];

    for (int i = 0; i < t; i++) {
        arr_1[i] = i + 1;
    }

    for (int i = 0; i < max; i++) {
        cin >> arr_2[i];
    }
    sort(arr_2, arr_2 + 28);

    for (int i = 0; i < t; i++) {
        bool check = true;
        for (int j = 0; j < max; j++) {
            if (arr_1[i] == arr_2[j]) {
                check = false;
                break;
            }
        }
        if (check == true)
            cout << arr_1[i] << " ";
    }


    return 0;
}
