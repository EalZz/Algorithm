#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, max = 0;
    //cin >> t >> max;
    t = 10;
    max = 10;

    int* arr_1 = new int[t];
    int* arr_2 = new int[max];

    for (int i = 0; i < t; i++) {
        cin >> arr_1[i];
        arr_2[i] = arr_1[i] % 42;
    }
    sort(arr_2, arr_2 + 10);
    
    int count = 1;
    for (int i = 1; i < t; i++) {
        if (arr_2[i - 1] != arr_2[i])
            count += 1;
    }

    cout << count << endl;

    return 0;
}
