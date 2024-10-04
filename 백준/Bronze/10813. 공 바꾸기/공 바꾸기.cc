#include <iostream>
using namespace std;

int main() {
    int t, max = 0;
    cin >> t >> max;

    int* arr = new int[t];

    for (int i = 0; i < t; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < max; i++) {
        int a, b, change;
        cin >> a >> b;

        change = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = change;
    }

    for (int i = 0; i < t; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
