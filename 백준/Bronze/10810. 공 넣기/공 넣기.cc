#include <iostream>
using namespace std;

int main() {
    int t, max = 0;
    cin >> t >> max;

    int* arr = new int[t];

    for (int i = 0; i < t; i++) {
        arr[i] = 0;
    }

    int start, end, num;

    for (int j = 0; j < max; j++) {
        cin >> start >> end >> num;
        for (int i = start - 1; i < end; i++) {
            arr[i] = num;
        }
    }
    
    for (int i = 0; i < t; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
